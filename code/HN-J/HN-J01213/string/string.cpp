#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long a,k=0,len=0,sum=0;
	string c;
	string s;
	for(int i=0; i<n; i++) {
		cin>>a>>c[i];
		len+=a;
		while(a--) {
			s[k]=c[i];
			k++;
		}
	}
	long long j=len-1;
	long long i=0;
	while(len&&j>i) {
		if(s[i]!=s[j]) {
			s[j]=s[i];
			sum++;
		}
		len--;
		j--;
		i++;
	}
	cout<<sum ;
	return 0;
}
