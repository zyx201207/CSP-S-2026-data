#include<bits/stdc++.h>
using namespace std;
long long a[2000005],sum;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    int c,t,n,d;
	cin>>c>>t;
	while(t--){
		sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n-3;i++){
		    int r=i+3;
		    if(a[r]-a[i]<=d) break;
		    if(a[r]-a[i+1]<=d&&a[i+1]-a[i]<=d){
			    if(a[r]-a[r-1]<=d&&a[r-1]-a[i]<=d){
				    sum++;
			    }
		    }
		}
		cout<<sum<<endl;
	} 
	return 0;
} 
