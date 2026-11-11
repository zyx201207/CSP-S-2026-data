#include<bits/stdc++.h>
using namespace std;
int s[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int p[n+5],ys[n+5];
	for(int i=1;i<=n;i++) cin>>p[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ys[j]=p[j];
			for(int r=i;r<=n;r++){
				if(ys[r]==ys[j]){
					for(int q=r;q<j;q++) ys[q]=0;
				}
			}
			
		}
		for(int j=i;j<=n;j++){
			//cout<<ys[j]<<" ";
			s[ys[j]]++;
		}
		//cout<<endl;
	}
	for(int i=1;i<=m;i++) cout<<s[i]<<" ";
	return 0;
}
