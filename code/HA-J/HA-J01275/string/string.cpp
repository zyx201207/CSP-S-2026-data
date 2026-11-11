#include<bits/stdc++.h>
using namespace std;
const int N=200005;
long long s[N]= {0};
char g[N];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int cnt=0;
	for(int i=1; i<=n; i++) {
		long long a;
		char b;
		cin>>a>>b;
		cnt++;
		s[i]+=a;
		g[i]=b;
	}
	
	long long ans=0;
	for(int i=1; i<cnt; i++) {
		long long a=s[i];
		while(a>0) {
			long long b=s[cnt];
			if(g[i]==g[cnt]) {
				if(a>b) {
					cnt--;
					a-=b;
				} else if(a<b) {
					s[cnt]-=a;
					a=0;
				} else {
					cnt--;
					a=0;
				}
			} else {
				if(a<b) {
					ans+=a;
					s[cnt]-=a;
					a=0;
				} else {
					ans+=b;
					cnt--;
					a-=b;
				}
			}
		}


	}
	cout<<ans<<endl;


	return 0;
}

