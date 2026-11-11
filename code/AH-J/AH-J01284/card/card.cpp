#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
bool t[300005]; 
int ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){//i~n
		memset(t,false,sizeof t);
		for(int j=i;j<=n;j++){
			if(t[a[j]]){
				for(int k=j-1;k;k--){
					t[a[k]]=false;
					if(a[k]==a[j])break;
				}	
			}
			t[a[j]]=true;
		}
		for(int j=1;j<=m;j++){
			ans[j]+=(t[j]==true);
		}
	} 
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
} 
