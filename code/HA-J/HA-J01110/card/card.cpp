#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100000],ans[100000],cnt[100000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
		    ans[i]=a[i];
		    for(int j=k;j<i;j++){
		    	if(ans[j]==ans[i]){
				    for(int x=n;x>j;x--){
					    ans[x]=0;
				    }
		    	}
		    }
    	}
    	for(int i=1;i<=n;i++){
		    cnt[ans[i]]++;
	   	}
    	for(int j=1;j<=n;j++){
	   		ans[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}
