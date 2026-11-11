#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int n,a[100005],ans=0;;
	char b[100005];
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++){
			s+=b[i];
		}
	}
	for(int i=0;i<s.length()/2;i++){
		if(s[i]!=s[s.length()-1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
