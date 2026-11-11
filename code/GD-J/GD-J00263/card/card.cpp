#include<bits/stdc++.h>
using namespace std;
int n,m,k[500005],p[300005],ne[300005];
long long a[500005],ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		ans[i]=i;
		if(p[a[i]]==0) p[a[i]]=i,k[i]=i;
		else k[i]=p[a[i]],p[a[i]]=i;
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<k[i];j++){
			ans[j]-=ans[i];
		}
	}
	for(int i=1;i<=m;i++) p[i]=0;
	for(int i=n;i>0;i--){
		if(p[a[i]]==0) ne[a[i]]=ans[i],p[a[i]]=1;
	}
	for(int i=1;i<=m;i++){
		cout<<ne[i]<<" ";
		
	}
	return 0;
} 
