#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t;
ll n,d,s[2000006];
int main (){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>s[i];
			int b=s[2]-s[1];
			int e=d/b;
			if(d%b==0)cout<<0;
			else cout<<e;
		}	
	}
}
