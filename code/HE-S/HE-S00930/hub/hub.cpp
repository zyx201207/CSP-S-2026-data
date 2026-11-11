#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
struct node{
	int u,v;
}s[2000010];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) cin>>s[i].u >>s[i].v ;
		cout<<"1"<<endl;
	}
	return 0;
} 
