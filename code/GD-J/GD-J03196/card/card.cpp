#include<bits/stdc++.h>
using namespace std;
long long  a[5000001],b[500001];
map<int,int>mp;
int n,m,ans[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
				if(b[a[j]]==1){
					
					for(int p=mp[a[j]]+1;p<j;p++){
						b[a[p]]=0;
					}
					mp[a[j]]=j;
				}else
				{
					b[a[j]]=1;
					mp[a[j]]=j;
				}
		}
		for(int j=1;j<=m;j++){
			ans[j]+=(b[j]);
		}
		memset(b,0,sizeof(b));
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//coder by:chen
