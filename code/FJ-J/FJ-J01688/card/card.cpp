#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[500005],b[300005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!b[a[i]]){
			b[a[i]]=i;
		}
		else {
			t[b[a[i]]]=i;
			b[a[i]]=i;
		}
	}	
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<=n){
			if(t[j]==0){
				ans[a[j]]++;
				j++;
				continue;
			}
			else j=t[j];
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0; 
}
