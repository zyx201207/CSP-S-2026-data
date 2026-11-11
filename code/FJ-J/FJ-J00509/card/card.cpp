#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],b[300005],v[505];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=500){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) v[j]=0;
			int l=0;
			for(int j=i;j<=n;j++){
				bool flag=0;
				int pos=0;
				for(int k=1;k<=l;k++) if(a[j]==v[k]) flag=1,pos=k;
				if(!flag) l++,v[l]=a[j];
				else l=pos;
			}for(int j=1;j<=l;j++) b[v[j]]++;
		}for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	}else{
		int now=m+1;
		for(int i=n;i>=1;i--) if(a[i]!=now) b[a[i]]=i,now=a[i];
		for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	}return 0;
}
