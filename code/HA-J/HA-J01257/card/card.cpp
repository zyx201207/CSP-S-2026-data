#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500005];
int ans[500005];
bool v[300005];
int l[300005];
bool ap[300005];

int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(v,0,sizeof(v));
		memset(ap,0,sizeof(ap));
		for(int j=i;j<=n;j++){
			if(v[a[j]]){
				int num=l[a[j]];
				for(int k=num+1;k<j;k++){
					v[a[k]]=0;
				}
				l[a[j]]=j;
			}else{
				v[a[j]]=true;
				l[a[j]]=j;
			}
		}
		for(int j=i;j<=n;j++){
			if(v[a[j]]&&!ap[a[j]]){
				ans[a[j]]++;
			}
			ap[a[j]]=1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
	
} 
