#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int ans[200005];
int ans1[200005];
int d[200005];
int main(){
	freopen("card1.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int p=1;p<=n;p++){
	    for(int i=p;i<=n;i++){
		    if(d[a[i]]>=1){
		    	int k=1;
		    	for(int j=i-1;j>=1;j--){
		    		if(ans[j]!=0) break;
		    		ans[j]=k;
		    		d[a[j]]--;
		    		k++;
		    		if(a[j]==a[i]) break;
		    	}
		    	d[a[i]]++;
	    	}
	    	else d[a[i]]++;
	    }
	    int k=1;
		for(int j=n;j>=1;j--){
		    if(ans[j]!=0) break;
		    ans[j]=k;
		   	k++;
		}
	    for(int i=p;i<=n;i++){
		    if(a[i]==p){
		    	ans1[p]+=ans[i];
		    }
	    }
    }
	for(int i=1;i<=n;i++){
		printf("%d\n",ans1[i]);
	}
	return 0;
}
