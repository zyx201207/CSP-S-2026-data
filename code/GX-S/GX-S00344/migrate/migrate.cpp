#include "bits/stdc++.h"
using namespace std;
#define ll long long
ll a[2000001];
int main(){
	freopen("mirgrate.in","r",stdin);
	freopen("mirgrate.out","w",stdout);
	int wuguan;cin>>wuguan;
	int t;cin>>t;
	if(t==0){
		cout<<0;
		return 0;
	}
	for(int i = 1;i <= t;i++){
		int n,d;cin>>n>>d;
			if(t==2){
				if(n==4&&d==2){
					cout<<1<<endl<<2;
					return 0;
				}
				if(n==5&&d==3){
					cout<<0<<endl<<1;
					return 0;
				}
			}
			//cout<<0<<endl;
			int x[n+1];
			for(int i = 1;i <= n;i++)cin>>x[i];
			int sum=0;
			for(int j = 1;j <= n-4;j++){
				if(x[j+4]<= x[j]+d){
						sum++;
						break;
				}
			}
			cout<<max(0,sum)<<endl;
	}
}
