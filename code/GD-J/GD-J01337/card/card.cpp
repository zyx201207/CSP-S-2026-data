#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],p[500005],top,d[300005],s[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		top=0;
		memset(d,0,sizeof(d));
		for(int j=i;j<=n;j++){
			if(d[a[j]]==0)p[top++]=a[j],d[a[j]]=top;
			else if(d[a[j]]<top)top=d[a[j]];
			else p[top++]=a[j],d[a[j]]=top;
		}for(int j=0;j<top;j++){
			s[p[j]]++;
		}
	}for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}

