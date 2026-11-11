#include<bits/stdc++.h>
using namespace std;
int a[50050],b[50050],ans=0,k;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m; 
	cin>>k>>m;
	a[0]=0;
	n=k-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i-1]=a[i]-a[i-1];
	}
	for(int i=n;i>=1;i--){
		long long minn;
		int sum[10010];
		sum[0]=1e5;
		for(int j=1;j<=n-i+1;j++){
			int c=1;
			for(int o=c;o<=i+c-1;o++){
				sum[j]+=b[o]*o;
				c++;
				if(c>=j){
					break;
				}
			}
			minn=min(sum[j],sum[j-1]);
		}
	    if(minn<=m){
	    	ans=i-1;
	    	break;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
