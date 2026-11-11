#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010];


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=0;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i+1] = a[i]-a[i-1];
	}
	for(int j=2;j<n;j++){
		int sj=0,num=0;
		for(int i=j;i<=n;i++){
		//	cout <<(num + (i-1)*(a[i]-a[i-1])) <<endl;
			if((num + (i-1)*(a[i]-a[i-1])) > m){
				break;
			}
			
			num += (i-1)*(a[i]-a[i-1]);
			sj = i-j+2;
		}
		
		if(ans < sj) ans = sj;
		
		
	}
	cout << ans;
	return 0;
} 
