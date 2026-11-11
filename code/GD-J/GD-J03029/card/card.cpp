#include<bits/stdc++.h>
using namespace std;
int a,b[300000],c[500000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>c[i];
	for(int k=0;k<n;k++){
		int ans=n-k;
		for(int i=k;i<n;i++){
			a=c[i];
			if(b[a]!=0){
				for(int j=b[a];j<i;j++)b[j]=0;
				ans-=b[a]-i;
			}else b[a]=i;
		}
		for(int i=0;i<m;i++)b[i]=0;
		if(ans==k+1)cout<<ans<<" ";
	}
	return 0;
} 
