#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans[N],v[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			v[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(v[a[j]]){
				for(int k=v[a[j]];k<j;k++) v[a[k]]=0;
				v[a[j]]=j;
			}else{
				v[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(v[j]) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
