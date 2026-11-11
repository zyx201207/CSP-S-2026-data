#include<bits/stdc++.h>
using namespace std;
const int N=200005;
struct zm{
	long long gs;
	char fh;
}s[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	 long long n,a,ans=0;
	char b;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		s[i].gs=a;s[i].fh=b;
	}
	long long r=n,l=1;
	while(l<r){
		if(int(s[l].fh)!=int(s[r].fh)){
			int t= min(s[l].gs,s[r].gs);
			ans+=t;
			if(t==s[l].gs){
				s[r].gs=s[r].gs-s[l].gs;
				l++;
			}
			else {
				s[l].gs=s[l].gs-s[r].gs;
				r--;
			}
		}
		else {
			int t= min(s[l].gs,s[r].gs);
			if(t==s[l].gs){
				s[r].gs=s[r].gs-s[l].gs;
				l++;
			}
			else {
				s[l].gs=s[l].gs-s[r].gs;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
