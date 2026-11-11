#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a[200005];
char c[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	LL x=1,y=s.size(),cnt=0;
	s=" "+s;
	while(x<=y){
		if(s[x]!=s[y]){
			cnt++;
		}
		x++;
		y--;
	}
	cout<<cnt;
	return 0;
}
