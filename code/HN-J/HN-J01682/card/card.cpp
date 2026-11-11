#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int ans[333333],a[555555],b[555555];
int n,m,f=0,anw=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=a[i-1]){
			f++;
		}
	}
	if(f==n){
		for(int i=1;i<=m;i++){
			cout<<n<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i,k=1;j<=n;j++,k++){
			anw=0;
			for(int x=1;x<=n;x++){
				if(a[j]!=b[x]){
					anw++;
				}else{
					for(int y=x+1;y<=n;y++){
						b[y]=0;
						k=x+1;
					}
				}
			}
			if(anw==n){
				b[k]=a[j];
			}
		}
		for(int e=1;e<=m;e++){
			ans[b[e]]++;
		}
		memset(b,0,sizeof(b));
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
