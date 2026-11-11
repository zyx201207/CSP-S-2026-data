#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+12;
int c,t;
int n,d;
int a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int flag=1;
		cin>>n>>d;
		cin>>a[1];
		cin>>a[2];
		int diff=a[2]-a[1];
		for(int i=3;i<=n;i++){
			cin>>a[i];
			if(a[i]-a[i-1]!=diff) flag=0;
		}
		if(flag){
			int jee=d/diff;
			if(d>a[n]-a[1]){
				cout<<0<<'\n';
				continue;
			}
			if(jee==1||jee==0) cout<<0<<'\n';
			else{
				cout<<n-2*jee+1<<'\n';
		}
		}
        }	
	fclose(stdin);
	fclose(stdout);	
}
