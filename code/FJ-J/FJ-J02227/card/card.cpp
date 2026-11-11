#include <bits/stdc++.h>
using namespace std;
const int MAXN=5*1e5+5;
const int MAXM=3*1e5+5;
int zhumian[MAXN];
int n,m;
int hand[MAXN];
int ans[MAXM];
int top=1;
int find_=-1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>hand[i];
	}
	for(int o=1;o<=n;o++){
		top=1;
		memset(zhumian,-1,sizeof(zhumian));
		for(int i=o;i<=n;i++){
			for(int j=1;j<=top;j++){
				if(zhumian[j]==hand[i]){
					find_=j;
					break;
				}
				find_=-1;
			}
			if(find_==-1){
				zhumian[top]=hand[i];
				top++;
			}else{
				top=find_;
				zhumian[top]=hand[i];
				top++;
			}
		}
		for(int i=1;i<=top;i++){
			ans[zhumian[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
