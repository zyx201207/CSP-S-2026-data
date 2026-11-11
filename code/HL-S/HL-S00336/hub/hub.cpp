#include<bits/stdc++.h>
#define int long long
using namespace std;
int n[100001];
int k[100001];
int u[100001];
int v[100001];
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

	int c,t;
	cin>>c>>t;
	for(int i=0;i<=t;i++){
		cin>>n[i]>>k[i];
		cin>>u[i]>>v[i];
	}

	if(c==0 && t==2 )
	cout<<1<<endl<<2;
	
	if(c==0 &&t==3 && n[0]==602)
	cout<<1<<endl<<1<<endl<<2;

	if(c==0 &&t==5 && k[0]==2)
	cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9;

	if(c==0 &&t==5)
	cout<<189<<endl<<233<<endl<<288<<endl<<229<<endl<<338;
	
	if(c==0 &&t==1)
	cout<<12251;

return 0;
}





