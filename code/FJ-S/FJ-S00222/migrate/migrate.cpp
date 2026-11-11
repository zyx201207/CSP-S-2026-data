#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int st,ed;
}nod[2000005]; 
int c,t,x[2000005],cc,ccc=1;
int find(int y,int u){
	return 1;
}
void solve(){
	int n,d,cnt=0,tt=0;
	memset(x,0,sizeof(x));
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=2;i<=n;i++){
		if(x[i]-x[i-1]>d){
			if(i-1-ccc>2){
				cc++;
				nod[cc].st=ccc;
				nod[cc].ed=i-1;	
			}
			ccc=i+1;
		}
	}
	if(n<4||cc>=n/3){
		cout<<0<<"\n";
		return;
	}
	for(int i=1;i<=cc;i++){
		tt+=find(nod[cc].st,nod[cc].ed);
	}
	cout<<tt<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) solve();
}
