#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],ans[300003];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int x=1;x<=n;x++){
		memset(b,0,sizeof(b));
		for(int i=x;i<=n;i++){
			if(b[a[i]]>0){
				for(int k=1;k<=m;k++){
					if(b[k]>b[a[i]])b[k]=0;
				}
			}
			b[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			if(b[i]!=0)ans[i]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
