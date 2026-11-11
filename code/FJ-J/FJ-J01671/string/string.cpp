#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,c,ans=0;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	long long l=0,r=n-1;
	while(l!=r){
		//cout<<a[l]<<b[l]<<" "<<a[r]<<b[r]<<endl;
		if(a[l]>=a[r]){
			if(b[l]!=b[r]){
				ans=ans+a[r];
			}
			//cout<<a[l]<<" "<<a[r]<<endl;
			a[l]=a[l]-a[r];r--;
			//cout<<a[l]<<"L"<<ans<<endl;
			
		}
		else{
			if(b[l]!=b[r]){
				ans=ans+a[l];
			}
			a[r]=a[r]-a[l];l++;
			//cout<<a[r]<<"R"<<ans<<endl;
		}
	}
	cout<<ans;
	return 0;
}

