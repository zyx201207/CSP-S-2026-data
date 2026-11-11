#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100010];
int v[100010];
int h[100010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=2;i<=n+1;i++){
		for(int j=i-1;j<=n;j++){
		    v[a[j]]++;
		    if(v[a[j]]>1){
		    	for(int k=1;k<=j-1;k++){
		    		v[a[k]]=0;
				}
			}	
		}
		for(int i=1;i<=n;i++)if(v[a[i]]==1)h[a[i]]++;
	}
	for(int i=1;i<=n;i++)cout<<h[a[i]]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
