#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],stk[N],b[N],ans[N],t=0;
bool u[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		
		memset(u,0,sizeof u);
		
		for(int j=i;j<=n;j++){
			int q=a[j];
			if(u[q]){
				while(stk[t]!=q){
					u[stk[t]]=0;
					t--;
				}
			}else{
				u[q]=1;
				stk[++t]=q;
			}
		}
		while(t){
			ans[stk[t]]++;
			t--;
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
} 
