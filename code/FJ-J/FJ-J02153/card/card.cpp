#include<bits/stdc++.h>
using namespace std;
int a[500005],b[300005],ans[300005],c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
		b[a[i]]++;
		c[a[i]]++;
	}
	for(int p=1;p<=n;p++){
	    for(int j=1;j<=n;j++){	
		b[j]=c[j];
		}
		if(p-1!=0){
			b[a[p-1]]--;
			c[a[p-1]]--;
		}
	    for(int i=p;i<=n;i++){
		for(int j=i+1;j<=n;j++){
		if(a[i]==a[j]){
			if(i==j-1){
				b[a[i]]-=2;
			}
			else{
			for(int k=i;k<=j-1;k++){
				b[a[k]]--;
			}  	
			}
		}
	}
	}	
	for(int k=1;k<=m;k++){
				ans[k]+=b[k];
		}
	}
	for(int k=1;k<=m;k++){
				cout<<ans[k]<<" ";
			}
	return 0;
} 
