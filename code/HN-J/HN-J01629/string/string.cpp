#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
struct S{
	int a ;
	char c;
}hw[N];
int n,da;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++) cin>>hw[i].a>>hw[i].c;
	int l=1,r=n;
	while(l<r){
		if(hw[l].c!=hw[r].c) da+=min(hw[l].a,hw[r].a);
		int x=hw[r].a,y=hw[l].a;
		hw[l].a-=x;
		hw[r].a-=y;
		if(hw[l].a<=0) l++;if(hw[r].a<=0) r--;
	}
	cout<<da;
	return 0;
}
