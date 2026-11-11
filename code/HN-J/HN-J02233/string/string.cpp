#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],ans;
char b[100005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		for(int j=0;j<a[i];j++){
			s+=b[i];
		}
	}
	for(int i=0;i<n;i++){
		if(s[i]==s[i-1]){
			ans++;
		}
	}
	if((ans+1)==n||ans==n) cout<<0;
	return 0;
} 
