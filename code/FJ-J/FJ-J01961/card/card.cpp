#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);	
	cin>>n>>m;
	int a[n]={},b[n]={};
	for(int i=1;i<=n;i++){
		 cin>>a[i];
		 b[a[i]]++;
	}
	for(int i=1;i<=m;i++) b[i]*=n;
	if(n==m){
		for(int i=1;i<=n;i++) cout<<n<<" ";
		return 0;
	} 
	for(int i=1;i<=n;i++){
		int h[m]={};
		for(int j=i;j<=n;j++){
			if(h[a[j]]!=0){
				for(int k=h[a[j]];k<j;k++){
					if(h[a[k]]!=0){
						b[a[k]]--;	
						h[a[k]]=0;
					}
				}
			}
			h[a[j]]=j;
		}
		b[a[i]]-=(n-i);
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" "; 
	return 0;
}
