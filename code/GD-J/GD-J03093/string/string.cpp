#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=2e5+5;
struct node{int l,r,siz;}a[M];
int n,cnt=1,ans,L;
char c[M];
string s=" ";
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int tmp;
		cin>>tmp>>c[i];
		for(int j=1;j<=tmp;j++)s+=c[i];
//		a[i].l=cnt,a[i].r=cnt+tmp-1;
//		a[i].siz=tmp;
//		cnt+=tmp;
	}
	L=s.size()-1;
	for(int i=1;i<=L/2;i++){
		if(s[i]!=s[L-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
