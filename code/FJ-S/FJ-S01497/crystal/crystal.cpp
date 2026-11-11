#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],s[500005];
bool check(int mid){
	for(int i=1;i<=n-mid+1;i++){
		if(mid*a[i+mid-1]-s[i+mid-1]+s[i-1]<=m){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    bool flag=0;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	long long ans=0;
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1; 
		}else{
			r=mid-1;
		}
	}
	cout<<r<<endl;
	return 0;
}

