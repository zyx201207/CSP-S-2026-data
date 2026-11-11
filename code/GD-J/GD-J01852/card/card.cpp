#include<bits/stdc++.h>
using namespace std;
int m,t;
int s[500005];
int sum=0;
int o[10005],p[10005];
void sub(int l,int r){
	memset(p,0,sizeof p);
	int st[50004],en=0;
	for(int i=l;i<=r;i++) {
		if(p[s[i]]==0) st[++en]=s[i],p[s[i]]++;
		else {
			while(st[en]!=s[i]) p[st[en]]--,en--;
		}
	}
	for(int i=1;i<=en;i++) o[st[i]]++;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>m>>t;
	for(int i=1;i<=m;i++) cin>>s[i];
	for(int i=1;i<=m;i++) sub(i,m);
	for(int i=1;i<=t;i++) cout<<o[i]<<' ';
}
