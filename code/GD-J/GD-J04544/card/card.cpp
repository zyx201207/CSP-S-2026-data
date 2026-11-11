#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7,Y=3e5+7;
long long n,m,a[N],ans[Y],b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	a[n+1]=0;
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		for(int j=i;j<=n+1;j++)b[j]=a[j];
		for(int j=i;j<=n+1;j++){
			for(int p=j+1;p<=n+1;p++){
				if(b[j]==b[p]){
					int s=p-j;
					for(int q=j;q<=p-1;q++){
						b[q]=b[q+s];
					}
					for(int q=p;q<=n+1;q++)b[q]=0;
				}
			}
		}
		for(int j=i;j<=n+1;j++){
			if(b[j]>0){
				ans[b[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
