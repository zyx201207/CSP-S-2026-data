#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s;
long long n,a[N],ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		long long la=a[i];
		while(la--) s+=c[i];
	}
	long long ls=s.size();
	if(ls%2==1){
		long long l=ls/2-1,r=ls/2+1;
		while(l>=0 && r<ls){
			if(s[l]!=s[r]){
				ans++;
			}l--;r++;
		}
	}else{
		long long l=ls/2-1,r=ls/2;
		while(l>=0 && r<ls){
			if(s[l]!=s[r]){
				ans++;
			}l--;r++;
		}
	}
	cout<<ans;
}

