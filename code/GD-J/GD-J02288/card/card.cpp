#include<bits/stdc++.h>
using namespace std;
int d[300005],ans[300005],a[300005];
long long n,m,k,num;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int ii=0;ii<=n;ii++){
		num=0;
    	for(int i=ii;i<=n;i++){
	    	num++;
	    	if(d[a[i]]==0) d[a[i]]=num;
	    	else{
		        for(int j=0;j<=m;j++)
		    	    if(d[j]>=d[a[i]]&&d[j]<=num) d[j]=0;
		    	num=d[a[i]]-1;
		    	d[a[i]]=0;
		    }
	    }
	    for(int j=0;j<=m;j++){
	    	if(d[j]!=0) ans[j]++;
	    	d[j]=0;
	    }
	}
	for(int i=1;i<=m;i++)
	    cout<<ans[i]<<' ';
	return 0;
}
