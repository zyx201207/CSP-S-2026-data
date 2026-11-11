#include<iostream>
#include<cstring>
#define int long long 
using namespace std;
const int N=2e5+10;
int n;
int a[N];
char c[N];
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int j=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		int cnt=a[i];
		while(cnt--){
			s+=c[i];
			j++;
		}
	}
	j--;
	int l=0,r=j,ans=0;
	while(l<=r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++;r--;
	}
	cout<<ans;
	return 0;
}
