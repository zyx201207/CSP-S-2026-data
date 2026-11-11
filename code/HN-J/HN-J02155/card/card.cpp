#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+10,M=3e5+10;
int a[N],ans[M],s[M],h[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	int T=n;
	while(T--){
		memset(s,0,sizeof s);
		memset(h,0,sizeof h);
		int l=n-T,k=1;
		for(int i=l;i<=n;i++){
			if(s[a[i]]==0){
				s[a[i]]=k;
				h[k]=a[i];
			}
			else {
				for(int j=s[a[i]]+1;j<k;j++){
					s[h[j]]=0;
					h[j]=0;
				}
				k=s[a[i]];
			}
			k++;
		}
		for(int i=1;i<=m;i++){
			if(s[i]!=0)ans[i]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
