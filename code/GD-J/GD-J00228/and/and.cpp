#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}long long ans=a[0];
	if(n==m){
		for(int i=1;i<n;i++){
			ans=(ans&a[i]);
		}cout<<ans;
	}else if(m==1){
		sort(a,a+n-1);
		cout<<a[0];
	}else if(m==2){
		long long ma=0,maa,mab;
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				//long long x=a[i]&a[j];
				if((a[i]&a[j])>ma){
					ma=(a[i]&a[j]);
					maa=a[i];
					mab=a[j];
					//cout<<ma<<' '<<maa<<' '<<mab<<endl;
				}//cout<<x<<endl;
			}
		}cout<<ma;
	}
	return 0;
} 
