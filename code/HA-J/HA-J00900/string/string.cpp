#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int sum;
int x[200005],s[200005];
char c[200005];
char ch(int u){
	for(int j=1;j<=n;j++){
		if(u<=s[j]){
			return c[j];
		}
	}
}
int f(int a){
	int ans=0;
	for(int i=1;i<=a/2;i++){
		if(ch(i)!=ch(a+1-i)) ans++;
	}
	return ans;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>c[i];
		s[i]=s[i-1]+x[i];
		sum+=x[i];
	}
	cout<<f(sum);
return 0;
}
