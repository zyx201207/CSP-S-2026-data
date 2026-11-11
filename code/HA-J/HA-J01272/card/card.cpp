#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m;
int a[N],ans[N],t[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		bool b[N]={false};
		memset(t,0,sizeof(t));
		for(int j=i;j<=n;j++){
			for(int k=i;k<j;k++){
				if(a[k]==a[j]){
					for(int o=k;o<j;o++){
						b[o]=false;
					}
				}
			}
			b[j]=true;
			t[j]=a[j];
		}
		for(int j=i;j<=n;j++){
			if(b[j]==true){
				ans[t[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
