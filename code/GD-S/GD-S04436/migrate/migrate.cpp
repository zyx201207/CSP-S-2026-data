#include<bits/stdc++.h>
using namespace std;

int c,t;


int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d,ans=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			int a;
			cin>>a;
			if(a>0){
				ans+=a;
			}
			else{
				ans-=a;
			}
		}
		ans/=n;
		cout<<ans-1<<endl;
	}
	return 0;
} 
