#include<bits/stdc++.h>
using namespace std;
long long a[200007];
string s[200007];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out ","w",stdout);
	long long n,d=0;
	long long ans=0;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i];
		cin>>s[i];
	}
	long long l=0,r=n-1;
	while(l<r){
		if(s[l]==s[r]){
			if(a[l]==a[r]&&d==0)l++,r--,d=1;
			if(a[l]<a[r]&&d==0){
				a[r]-=a[l];
				d=1;
				l++;
			}
			if(a[r]<a[l]&&d==0){
				a[l]-=a[r];
				d=1;
				r--;
			}
		}
		if(s[l]!=s[r]&&d==0){
			if(a[l]==a[r]&&d==0)ans+=a[l],l++,r--,d=1;
			if(a[l]<a[r]&&d==0){
				ans+=a[l];
				a[r]-=a[l];
				d=1;
				l++;
			}
			if(a[r]<a[l]&&d==0){
				ans+=a[r];
				a[l]-=a[r];
				d=1;
				r--;
			}
		}
		d=0;
	}
	cout<<ans;
	cout<<"\n";
	return 0;
}
