#include<bits/stdc++.h>
using namespace std;
int n,m;
int sum[500000],mark[500000],a[500000],b[500000]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			b[j]=0;
		}
		for(int j=1;j<=m;j++){
			mark[j]=0;
		}
		int q=1;
		for(int j=i;j<=n;j++){
			b[q]=a[j];
			if(mark[a[j]]>=1){
				for(int l=j-1;l>=1;l--){
					if(b[l]==a[j]){
					mark[b[l]]-=1;
					b[l]=0;
					break;
					}	
				}
			}
		}
		for(int i=1;i<=m;i++){
			 if(mark[i]>=1){
			 	sum[i]+=1;
			 }
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<endl;
	}
}
