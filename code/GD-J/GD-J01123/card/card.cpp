#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int arr[N],ans[M];
bool v[M]={0},mp[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++){
		
		for(int j=i;j<=n;j++){
			if(mp[arr[j]]==0){
				mp[arr[j]]=1;
				v[arr[j]]=1;
			}
			else{
				for(int k=j-1;k>=i;k--){
					if(arr[k]==arr[j]){
						break;
					}
					mp[arr[k]]=0;
					v[arr[k]]=0;
				}
			}
			
		}
		for(int j=1;j<=m;j++){
			if(v[j]==1){
				ans[j]++;
			}
		}
		memset(v,0,sizeof v);
		memset(mp,0,sizeof mp);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
