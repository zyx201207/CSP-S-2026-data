#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,n;
	cin>>n;
	string s,c;
	long long st=0;
	for(long long i=0; i<n; i++) {
		cin>>a>>c;
		st+=a;
		for(long long j=0; j<a; j++) {
			s+=c;
		}
	}
	long long ans=0;
for(int i=0; i<st/2; i++) {
		if(st%2!=0) {
			for(int j=st-1; j>st/2; j--) {
				if(s[j]!=s[i]) {
					s[j]=s[i];
					ans+=1;
					
				}
			}
		} else {
			for(int j=st-1; j>=st/2; j--) {
				if(s[j]!=s[i]) {
					s[j]=s[i];
					ans+=1;
				}
			}
		}

	}
	cout<<ans;
	return 0;
}





