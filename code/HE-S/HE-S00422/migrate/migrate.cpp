#include<bits/stdc++.h>
using namespace std;
int n,t,c;
long long a[2000200];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		int n;
		long long d;
		cin>>n>>d;
		long long cha;
		bool b=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i==2){
				cha=a[2]-a[1];
			}
			if(i>2&&a[i]-a[i-1]!=cha){
				b=true;
			}
		}
		if(b==0){
			long long x=d/cha;
			if(x<=1){
				cout<<"0"<<'\n';
			} else{
				cout<<max(n-(2*x)+1,(long long)0)<<'\n';
			}	
		}
	}
	return 0;
} 
