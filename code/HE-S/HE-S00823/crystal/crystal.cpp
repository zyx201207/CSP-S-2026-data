#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
    int n;
long long m,ans=0;
long long k=1;
long long i=0;
	cin>>n>>m;
	vector<int>a(n);
	for(int f=0;f<n;f++){
		cin>>a[f];
	}
	sort(a.begin(),a.end());
	while(i+k<=n){
		long count=0;
		long m1=m;
		long long imp=1;
		for(long long j=i;j<i+k;j++){
			if(a[i+k]-a[i+k-imp]<=m1){
				m1=m1-a[i+k]+a[i+k-imp];
				count++;
				imp++;
			}
		}
		if(count>ans){
			k++;
			ans=count;
		}else{
			i++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
