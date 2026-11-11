#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[200001],ans=0;
	char c[200001];
	string s;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(long long j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	long long j=s.size()-1;
	for(long long i=0;i<s.size();i++){
		if(s[i]==s[j]){
			j--;
		}else{
			ans++;
			j--;
		}
		if(j<i){
			cout<<ans;
			return 0;
		}
	}
	cout<<ans;
	return 0;
}
