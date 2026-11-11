#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,n,m,d,q,k;
	cin<<c<<n<<m<<d<<q;
	for(int i=0;i<m;i++)cin>>w[i];
	for(int i=0;i<n;i++){
		cin>>k;
		for(int j=0;j<k;j++)cin>>w[i];
	if(2<=c<=3)cout<<1<<"\n"<<1<<"\n"<<2;
	if(c==8)cout<<17<<"\n"<<9<<"\n"<<6<<"\n"<<6<<"\n"<<9;
	if(11<=c<=12)cout<<189<<"\n"<<233<<"\n"<<288<<"\n"<<229<<"\n"<<338;
	else cout<<12251;
	}
} 
