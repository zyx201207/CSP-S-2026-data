#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m,a[N]/*,last[N][M]*/,ans[M];
bool flag;
map<int,int> bl;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//last[i][a[i]]=i;
		bl[a[i]]++;
		if(a[i]>=a[i-1]){
			flag=true;
		}else{
			flag=false;
		}
	}
	/*if(!flag){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(last[i][j]==0){
					last[i][j]=last[i-1][j];
				}
			}
		}
		for(int i=1;i<=n;i++){
			map<int,int> ma=bl;
			for(int j=i;j<=n;j++){
				for(int k=last[j-1][a[j]];k<=last[j][a[j]];k++){
					ma[a[k]]--;
				}
			}
			for(auto x:ma){
				ans[x.first]+=x.second;
			}
		}for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}*/
	if(flag){
		for(int i=1;i<=n;i++){
			for(int j=a[i];j<=m;j++){
				ans[j]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}
}

