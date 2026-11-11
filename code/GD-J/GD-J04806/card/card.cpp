#include<bits/stdc++.h>
using namespace std;
const int maxn=500005,maxm=300005;
int a[maxn],ans[maxm],check[maxn][2],s[maxm];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(ans,0,sizeof(ans));
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(check,0,sizeof(check));
		memset(s,0,sizeof(s));
		for(int j=i;j<=n;j++){
			if(s[a[j]]){
				for(int k=check[a[j]][s[a[j]]];k<j;k++){
					s[a[k]]=0;
				}
			}
			s[a[j]]=1;
			check[a[j]][s[a[j]]]=j;
		}
		for(int j=1;j<=m;j++){
			if(s[j]){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
