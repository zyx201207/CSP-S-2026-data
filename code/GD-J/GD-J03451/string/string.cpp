#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a,ans=0;
char c[100000010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int l=1;
	for(int i=1;i<=n;i++){
		cin>>a;
		char C;
		cin>>C;
		while(a--){
			c[l]=C;
			l++;
		}
	}l--;
	for(int i=1;i<=l/2+1;i++){
		int j=l-i+1;
		if(i>j){
			break;
		}
		if(c[i]!=c[j]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
