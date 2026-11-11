#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int mp[500005],ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(mp[a[j]]!=0){
				for(int k=mp[a[j]];k<=j;k++){
					mp[k]=0;
				}
			}else mp[a[j]]=i;
			
		}for(int j=1;j<=m;j++){
			if(mp[j]!=0)ans[j]++;
			mp[j]=0;
		}
	}for(int i=1;i<=m;i++){
		cout<<ans[i]<<endl;
	}return 0;
}