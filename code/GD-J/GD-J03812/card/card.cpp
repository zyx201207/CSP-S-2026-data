#include <bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
const int M=3*1e5+10;
int n,m,a[N],cnt[M],st[N],top,idx[M],f[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		top=0;
		memset(idx,0,sizeof(idx));
		memset(f,0,sizeof(f));
		
		for(int j=i;j<=n;j++){
			if(idx[a[j]]!=0){
				top=idx[a[j]]-1;
			}
			top++,st[top]=a[j],idx[a[j]]=top;			    
		}
		for(int j=1;j<=top;j++){
			if(f[st[j]]==0) cnt[st[j]]++,f[st[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	
	return 0;
}
