#include <bits/stdc++.h>
using namespace std;
char s[10000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n;
	long long t1=0;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a;
		cin>>c;
		for(long long j=t1;j<=t1+a;j++){
			s[j]=c;
		}
		t1+=a;
	}
	for(int i=1;i<=t1;i++){
		for(int j=i;j<=t1;j++){
			if(s[i]!=s[j]){
				ans++;
			}
		}
	}
	cout<<ans;	
	return 0;
}
