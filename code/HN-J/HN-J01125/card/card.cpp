#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int l=0;
	cin>>n>>m;
	int w[200000];
	int t[200000];
	int s[200000];
	for(int q=0;q<=m-1;q++){
		s[q]=0;
	}
	for(int j=0;j<=m-1;j++){
		t[j]=j++;
	}
	for(int i=0;i<=n-1;i++){
		cin>>w[l];
		for(int y=0;y<=l;y++){
			if(w[l]=w[y]){
				l=y;
			}
			else{
				l=l;
			}
		} 
		for(int r=0;r<=l;r++){
			for(int u=0;u<=m;u++){
				if(w[r]=t[u]){
					s[u]++;
				}
				else{
					s[u]=s[u];
				}
			}
		} 
	}
	return 0;
}
