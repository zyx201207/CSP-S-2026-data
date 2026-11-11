#include <bits/stdc++.h>
using namespace std;
long n,a;
char c;
string s;
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	cin>>n;
	for (long long i=1;i<=n;i++){
		cin>>a>>c;
		for (long long j=1;j<=a;j++) s+=c;
	}
	int mid=s.size()/2;
	long long ans=0,j=1;
	if (s.size()%2==1){
		for (long long i=0;i<mid;i++){
			if (s[mid+j]!=s[mid-j]) ans++;
			j++;
		}
	}
	else {
		long long k=0;
		for (long long i=0;i<mid;i++){
			if (s[mid+k]!=s[mid-j]) ans++;
			j++;
			k++;
		}
	}
	cout<<ans;
	return 0;
}
