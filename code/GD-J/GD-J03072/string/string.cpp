#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int ans; 
	char o;
	int k=0;
	for (int i=1;i<=n;i++) {
		cin>>ans>>o;
		for (int j=1;j<=ans;j++)  {
			s+=o;
		}
		k+=ans;
	}
	string a=s;
	reverse(s.begin(),s.end());
	if (a==s) {
		cout<<0<<endl;
		return 0;
	}	
	long long sum=0;
	for (int i=0;i<s.size()/2;i++) {
		if (a[i]!=s[i]) {
			sum++;
		}
	}
	
	cout<<sum<<endl;
	
	
	return 0;
}
 
