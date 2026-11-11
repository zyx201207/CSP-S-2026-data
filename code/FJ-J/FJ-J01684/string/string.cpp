#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n;
int a[N];
char c[N];
string s="";
int ans=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	int y=s.size();
	if(y%2==0){
		int q=y/2;
		int p=y/2-1;
		for(;q<y;q++,p--){
			if(s[q]!=s[p]){
				ans++;
			}
		}
	}
	if(y%2==1){
		int q=(y+1)/2;
		int p=q-2;
		for(;q<y;q++,p--){
			if(s[q]!=s[p]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
