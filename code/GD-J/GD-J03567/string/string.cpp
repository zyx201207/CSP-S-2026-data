#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int a[N],tlen,tlen0;
struct node{
	int first,second;
	string a;	
}pos1[N],pos2[N];
string c[N],s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,tot=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		tot+=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	
	int cnt=0;
	for(int i=1;i<=tot/2;i++){
		if(s[i]!=s[tot-i+1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
