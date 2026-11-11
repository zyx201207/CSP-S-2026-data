#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,mid;
	cin>>n;
	long long a[n+5];
	long long sum=0;
	char c[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	long long ans=0;
	string s;
	for(int i=1;i<=n;i++){
	for(int j=1;j<=a[i];j++){
		s+=c[i];
	}
		}
		if(sum%2==0)mid=sum/2;
		else mid=sum/2+1;
	for(long long i=sum-1;i>=mid;i--){
		if(s[i]!=s[sum-i-1]){
			ans++; 
		}
	}
	cout<<ans;
	return 0;
} 
