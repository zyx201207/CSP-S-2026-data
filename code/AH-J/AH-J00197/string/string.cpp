#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		long long int a;char b;cin>>a>>b;
		for(long long int j=1;j<=a;j++){
			s+=b;
		}
	}
	long long int sum=0;
	for(long long int i=0,j=s.size()-1;i<=j;i++,j--){
		if(s[i]!=s[j])sum++;
	}
	cout<<sum;
	return 0;
}
