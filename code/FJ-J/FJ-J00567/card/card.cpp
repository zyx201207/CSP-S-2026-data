#include<bits/stdc++.h>
using namespace std; 
int n,m,a[500005],tk,b[300005],ans[300005];
vector<int>s[300005];
bool mn[5005],fmn[5005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]=i;
		s[a[i]].push_back(i);
		if(a[i]<a[i-1])tk=1;
	}if(tk==0){
		for(int i=1;i<=m;i++){
			cout<<b[i]<<" ";
		}
	}else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)mn[j]=0;
			for(int j=i;j<=n;j++){
				for(int z=j-1;z>=i;z--){
					if(a[z]==a[j]&&mn[z]!=1){
						for(int to=z;to<j;to++){
							mn[to]=1;
						}
					}
				}
			}for(int j=i;j<=n;j++){
				if(mn[j]==0){
					ans[a[j]]++;
				}
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}
	return 0;
} 
