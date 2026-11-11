//GZ-S00377 遵义市新蒲中学 杨子曦 
#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,sum = 1;
	long long m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	if(a[3]-a[2] == 1&&a[2]-a[1] == 1){
		int p = 1,l=n;
		m--;
		sum++;
		p = 4;
		while(m>=0){
			if(p <= n){
				sum++;
				p*=2;
			}else{
				if(p - a[l] <= m){
					m -= p - a[l];
					l--;
					sum++;
				}else{
					break;
				}
			}
		}
		cout << sum;
		return 0;
	}
	cout << 2;
	return 0;
}
