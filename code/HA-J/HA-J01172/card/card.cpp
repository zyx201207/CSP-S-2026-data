#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int c[500010]={};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	while(n--){
		int ans[500010]={};
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(c[i]!=ans[j]){
					ans[j]=c[i];
					break;
				}
				else{
					
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
