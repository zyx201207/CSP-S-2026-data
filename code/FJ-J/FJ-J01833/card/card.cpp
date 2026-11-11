#include<bits/stdc++.h>
using namespace std;
int n,m,a[512345],cnt[312345],ans[312345],l;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	ans[a[n]]=n;
	for(int i=n-1;i>=1;i--){
		if(ans[a[i]]!=0) continue;
		else{
			for(int j=1;j<i;j++)
				for(int k=i+1;k<=n;k++)
					if(a[j]==a[k]) l++;
		}
		ans[a[i]]=i-l;
		l=0; 
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
} 

