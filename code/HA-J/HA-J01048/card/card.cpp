#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[300005],ans[300005],tt[500005];bool f=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])f=0;
        ans[a[i]]= max(n-i+1,ans[a[i]]);
	}
    if(n==m or f){
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
    }
    int l=1;
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=n;i++){
    	int p=0;
		if(f)p=lower_bound(a+1,a+i,a[i])-a;
		else {
			for(int j=1;j<i;j++){
				if(a[j]==a[i] and tt[j]){
					p=j;
					break;
				}
			}
		}
    	if(a[p]==a[i] and t[a[i]]){
    		for(int j=p;j<i;j++){
    			t[a[j]]--;tt[j]=0;
    		}
    		l=i;
    	}
    	t[a[i]]++;tt[i]=1;
    	for(int j=1;j<=m;j++){
    		if(t[j])ans[j]++;
    	}
    }
    for(int i=1;i<=m;i++){
     cout<<ans[i]<<" ";
    }
	return 0;
}
