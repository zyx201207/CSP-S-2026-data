#include<bits/stdc++.h>
using namespace std;
char s1[2000005],s2[2000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long cnt=0;
	while(n--){
		long long t;
		char c;
		cin>>t>>c;
		for(long long i=0;i<t;i++){
			s1[i+cnt]=c;
		}
		cnt+=t;
	}
	for(long long i=0;i<cnt;i++){
		s2[cnt-i-1]=s1[i];
	}
	int ans=0;
	for(long long i=0;i<cnt;i++){
		if(s1[i]!=s2[i]) ans++;
	}
	cout<<ans/2;
	return 0;
}
