#include <bits/stdc++.h>
using namespace std;
const int N=3e5+5,M=5e5+5;
long long n,m,a[M],w[N],sta[N],top,ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(w,0,sizeof(w));
		top=0;
		for(int j=i;j<=n;j++){
			if(w[a[j]]==0){
				w[a[j]]=++top;
				sta[top]=a[j];
			}
			else{
				while(sta[top]!=a[j])w[sta[top--]]=0;
			}
		}
		for(int j=1;j<=m;j++){
			if(w[j])ans[j]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
