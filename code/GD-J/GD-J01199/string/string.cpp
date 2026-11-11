#include<bits/stdc++.h>
#define int long long
const int N=2e5+10;
using namespace std;
int n,ans,cnt;
string st;
struct f{
	int x;
	char c;
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		cnt+=a[i].x;
		for(int j=1;j<=a[i].x;j++)st+=a[i].c;
	}st=' '+st;
	for(int l=1,r=cnt;l<=r;l++,r--){
		if(st[l]!=st[r])ans++;
	}cout<<ans;
	return 0;
} 
