//GZ-S00068 清镇市第一中学 蒋煜
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010];
int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(long long i = 1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	long long s=1,ff=1;
	while(m>0){
		if(a[s]==a[s+1]){
			s++;
			ff++;
		}
		else if(a[s]<a[s+1]){
			for(long long i = 1;i<=ff;i++){
				a[i]++;
			}
			m-=ff;
		}
	}
	long long num = 1;
	for(long long i = 1;i<=n;i++){
		if(a[i]==a[i+1])num++;
	}
	cout << num;
	return 0;
}
