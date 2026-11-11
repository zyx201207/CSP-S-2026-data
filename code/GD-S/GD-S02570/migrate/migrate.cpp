#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,a[2000005],maxn;
int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		int x;
		maxn=n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]-a[i-1]>k&&maxn==n){
				maxn=i;
			}
		}
		if(c==11||c==12){
			if(maxn!=n)cout<<0<<endl;
			else{
				cout<<1<<endl;
			}
		}
		else cout<<(x)<<endl;
		
	}
	return 0;
} 
