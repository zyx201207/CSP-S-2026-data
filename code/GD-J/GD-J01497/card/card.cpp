#include<bits/stdc++.h>
using namespace std;
int a[500010],ans[300010],m[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m<=2){
		for(int i=1;i<=n;i++){
			ans[a[i]]++;
			if(a[i]!=a[n])ans[a[n]]++;
		}
	}else if(n<=500){
		int last[300010];
		for(int i=1;i<=n;i++){
			memset(last,0,sizeof(last));
			int len=0,t[510];
			for(int j=i;j<=n;j++){
				if(last[a[j]]==0){
					last[a[j]]=++len;
					t[len]=a[j];
				}else{
					for(int k=last[a[j]]+1;k<=len;k++){
						last[t[k]]=0;
						t[k]=0;
					}
					len=last[a[j]];
				}
			}
			for(int j=1;j<=len;j++)ans[t[j]]++;
		}
	}else{
		int s=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i-1]){
				ans[a[i-1]]=i-1;
			}
		} 
		ans[a[n]]=n;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
