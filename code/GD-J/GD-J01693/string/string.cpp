#include<bits/stdc++.h>
using namespace std;
string s[1000100],up;
long long a[1000100];
int main(){
	long long n;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i];
		cin>>s[i];
		for(long long j=1;j<=a[i];j++){
			up+=s[i];
		}
	}
	long long ans=0,l=0,r=n;
	long long c=up.size();
	for (long long i=0;i<c/2;i++){
		if(up[l] == up[r]){
			l++;
			r--;
			continue;
		}
		else if(up[l] != up[r]){
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
