#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,a[N],l;
char c[N];
string s;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
//	cout<<s<<"\n";
	for(int i=1;i<=(l+1)/2;i++){
		int ii=i;
		if(s[ii-1]!=s[l+1-ii-1]){
			ans++;
		}
	}
	cout<<ans<<"\n";
	return 0;
} 

