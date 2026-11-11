#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s;
long long n,a[N],l,r,ans,ls,rs;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	l=1,r=n;
	ls=a[1],rs=a[n];
	while(l<=r){
		int bl=min(ls,rs);
		if(c[l]!=c[r])ans+=bl;
		ls-=bl;
		rs-=bl;
		if(ls==0){
			l++;
			ls=a[l];
		}
		if(rs==0){
			r--;
			rs=a[r];
		}
	}
	cout<<ans;
}
