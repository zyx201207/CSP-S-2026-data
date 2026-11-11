#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long a[n+1];
	string s[n+1];
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	long long l=1,r=n;
	long long ans=0;
	//long long last=0;
	//char lastc;
	//bool b=0;
	while(l<r){
		if(s[l]!=s[r])
			ans+=min(a[l],a[r]);
		//last=(max(a[l],a[r])-min(a[l],a[r]));
		if(a[l]==a[r]){
			r--;
			l++;
		}
		else if(a[l]>a[r]){
			a[l]=a[l]-a[r];
			r--;
		//	b=0;
		}
		else{
			a[r]=a[r]-a[l];
			l++;
		//	b=1;
		}
	}
	cout<<ans;
}
