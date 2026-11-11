#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500100];
long long ma;
long long sum;
long long ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	ma=max(a[i],ma);
	}
	sort(a+1,a+1+n);
    for(int i=1;i<=ma;i++){
    	ans=0;
		long long u=m;
    	for(int j=1;j<=n;j++){
    		if(a[j]==i){
    			ans++;
			}else
    		if(i>a[j]){
    		u=u-i+a[j];	
    		if(u>=0){
		    	ans++;
			}else{
				break;
			}
			}
		}
		sum=max(ans,sum);
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
