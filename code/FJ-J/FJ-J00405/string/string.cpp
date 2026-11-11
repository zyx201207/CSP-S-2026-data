#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	string s="";
	ll len=0;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
		len+=a;
	}
	int sum=0;
	//cout<<s<<"\n";
	for(ll i=0;i<=(len-1)/2;i++){
		if(s[i]!=s[len-1-i]){
			sum++;
		}
		//cout<<i<<" "<<len-1-i<<"\n";
	}
	cout<<sum;
	return 0;
}
