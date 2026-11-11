//T4 ±©Á¦O(n^3) //12·Ö 
#include<bits/stdc++.h>
using namespace std;
const long long MAXNm=3*1e5+5,MAXNn=5*1e5+5;
int n,m;
long long ans[MAXNm],a[MAXNn];
int main(){
	freopen("card3.in","r",stdin);
	freopen("card3.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		bool flag[MAXNn],fa[MAXNm];
		int l[MAXNm];
		for(int j=i;j<=n;++j){
			flag[j]=true;
			if(fa[a[j]]==true){
				for(int k=l[a[j]];k<j;++k){
					flag[k]=false,fa[a[k]]=false;
				}
			}
			fa[a[j]]=true;
			l[a[j]]=j;
		}
		for(int j=i;j<=n;++j){
			if(flag[j]==true) ans[a[j]]++;
		}
	}
	cout<<endl;
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<" ";
	}
	return 0;
}
