#include<bits/stdc++.h>
using namespace std;
int n,m,a[50005],ans[30005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int c[30005],d[50005],t=1;
		bool b[30005];
		for(int j=i;j<=n;j++){
			if(b[a[j]]){
				t-=j-c[a[j]];
				c[a[j]]=j;
			}else{
				b[a[j]]=1;
				c[a[j]]=j;
				d[t]=a[j];
			}
			t++;
		}
		for(int j=1;j<t;j++)ans[d[j]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" "; 
	}
	return 0;
} 
