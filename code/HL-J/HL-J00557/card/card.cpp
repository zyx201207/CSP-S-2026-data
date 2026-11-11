#include<bits/stdc++.h>
using namespace std;
int s[500500];
int y[500500];
int c[500500];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int f=1;
	for(int i=1;i<=n;i++) cin>>s[i];
	
	for(int i=1;i<=n;i++) c[i]=s[i];
	
	for(int r=1;r<=n;r++){
		f=1;
		for(int i=1;i<=n&&i>=r;i++) s[i]=c[i];
		for(int i=r;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(s[i]==s[j]&&i!=j){
					for(int k=i;k<j;k++) s[k]=0;
				}
			}
		}
		
		for(int i=1;i<=m;i++){
			for(int j=r;j<=n;j++){
				if(s[j]==i){
					y[i]++;
					f=0;
					break;
				}
			}
			if(f==0) break;
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<y[i]<<" ";
	}
	
	return 0;
}
