#include<bits/stdc++.h>
using namespace std;
const int N=1e9+10;
long long n;
long long m;
long long a[N];
long long ans=0;
long long cnt=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	cin>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<n;i++){
		if(a[i]<a[i+1]){
			ans=a[i];
			a[i]=a[i+1];
			a[i+1]=ans;
		}
	}
	if(m==1){
		cnt+=a[1];
	}
	else{
		cnt+=a[1] and a[2];
	}
	for(long long i=2;i<=m;i++){
		cnt+=cnt and a[i+1];
	}
	cout<<cnt;
	return 0;
}
