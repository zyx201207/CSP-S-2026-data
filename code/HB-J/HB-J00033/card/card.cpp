#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[300010],val[300010],st[500010],top;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;++i){cin>>a[i];}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) cout<<a[j]<<" ";
		cout<<"\n";
		memset(val,0,sizeof val);
		top=0;
		for(int j=i;j<=n;++j){
			int v=a[j];
			if(val[v]){while(st[top]!=v){st[top]=0,val[st[top--]]=0;}}
			else{val[v]=1,st[++top]=v;}
		}
		while(top>0){ans[st[top]]++,st[top--]=0;}
	}
	cout<<a[n];
	for(int i=1;i<=m;++i) cout<<ans[i]<<" ";
	//10 3
	//3 1 2 1 3 2 3 1 2 1
	return 0;
}

