#include <iostream>
#include <algorithm>
using namespace std;
long long int n,m;
long long a[514514];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long x=0;
	sort(a+1,a+n+1);
	if(a[1]<0) x=abs(a[1]);
	for(int i=1;i<=n;i++){
		a[i]+=x;
		a[i]+=a[i-1];
		//cout<<a[i]<<' ';
	}
	//cout<<endl;
	//cout<<a[1];
	int l=1,r=1;
	//return 0;
	while(l<n||r<n){
		if(r>n)r=n;
		//cout<<r<<n<<endl;
		//cout<<(r-l+1)<<"*"<<(a[r]-a[l-1])<<"-"<<(a[r]-a[l-1])<<endl;
		if((r-l+1)*(a[r]-a[r-1])-(a[r]-a[l-1])<=m){
			
			mx=max(mx,(r-l+1));
			//cout<<l<<" "<<r<<" "<<mx<<endl<<(r-l+1)*(a[r]-a[r-1])-(a[r]-a[l-1])<<endl;
			r++;
			if(r==n)break;
			
		}
		else{
			if(l==r){
				r++;
			}
			l++;
		}
	}
	cout<<mx;
	return 0;
} //0 2 5 5 10
