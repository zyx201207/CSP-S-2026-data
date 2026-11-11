#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[245000],len[5],s[5],ans;
char c[245000],p;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	s[0]=0;
	s[1]=n+1;
	while(s[0]<n||s[1]>1){
		while(len[0]<=len[1]&&s[0]<n){
			s[0]++;
			ans+=min(len[1]-len[0],a[s[0]])*(p!=c[s[0]]);
			len[0]+=a[s[0]];
		}
		p=c[s[0]];
		while(len[1]<=len[0]&&s[1]>1){
			s[1]--;
			ans+=min(len[0]-len[1],a[s[1]])*(p!=c[s[1]]);
			len[1]+=a[s[1]];
		}
		p=c[s[1]];
	}
	cout<<ans/2;
	return 0;
}


