#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
long long ans;
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
    if(m==1){
    	sort(a+1,a+1+n);
    	cout<<a[n];
	}
	long long sum=0;
	if(m==2){
		for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
        ans=a[i] and a[j];
    		sum=max(sum,ans);
		}	
		}cout<<sum;
	}
	
    	

return 0;
}

