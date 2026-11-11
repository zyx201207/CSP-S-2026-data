#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	} 
	long long l=1,r=n;
	sort(a+1,a+1+n);
	long long fans=0,t;
	while(l<r){
		
		long long mid=(l+r)/2,ans=0,minans=0x7fffffffffffff;

		for(int i=mid;i<=n;i++){
			for(int o=i;o>=i-mid+1;o--){
				ans+=a[i]-a[o];
			
			}
			//ans=b[i]-b[i-mid]
			minans=min(minans,ans);
		} 

		if(minans==m){
			fans=mid;
			break;
		}else if(minans<m){
			fans=mid;
			l=mid+1;
		}else{
			fans=mid;
			r=mid-1;
		}

	}
	int k=fans;
	//cout<<k;
	for(int i=fans;i<=n;i++){
		if(a[i]==a[i+1]){
			k++;
		}else{
			break;
		}
		//cout<<" "<<a[i]<<" ";
	}
	cout<<k;
	return 0;
}
