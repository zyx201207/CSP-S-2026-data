#include<bits/stdc++.h>
using namespace std;
const int N=5*10e5+5;
int c,n,m,d,p;
int w[N],a[N],t[N],f[N],mp[10005][10005];

int di(int st,int en){
	int f1[N];
	for(int i=1;i<=m;i++)f1[i]=f[i];
	int mi[N];
	queue<int>q;
	q.push(st);
	mi[st]=0;
	while(!q.empty()){
		int i=q.front();
		q.pop();
		for(int j=1;j<=m;j++){
			if(mp[i][j]){
				mi[j]=min(mi[j],mi[i]+mp[i][j]);
				if(f1[j]){
					q.push(j);
					f1[j]--;
				}
			}
		}
	}
	return mi[en]+w[st]+w[en];
}
int main(){
	freopen("subway1.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c;
	memset(mp,0,sizeof(mp));
	cin>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			mp[a[j]][a[j-1]]=mp[a[j-1]][a[j]]=t[j]+t[j-1];
		}
	}
	for(int i=1;i<=m;i++)
	    for(int j=1;j<=m;j++){
	    	if(mp[i][j])f[i]++;
	    }
	
	while(p--){
		int a1,a2;
		cin>>a1>>a2;
		cout<<di(a1,a2)<<endl;
	}
	return 0;
}
