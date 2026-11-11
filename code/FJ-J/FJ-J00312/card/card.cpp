#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1],ans[n+1]={0},b[n+1],x[n+1]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	for(int i=1;i<=n;i++){
		int q=0;
		for(int j=i;j<=n;j++){
			if(x[a[j]]==0 || q==0){
				q++;
				b[q]=a[j];
				x[a[j]]=q;
			}
			else{
				for(int y=x[a[j]];y<=q;y++){
					x[b[y]]=0;
				}
				q=x[a[j]];
				
			}	
		}
		for(int j=1;j<=n;j++){
			x[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}