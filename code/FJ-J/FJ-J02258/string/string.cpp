#include<bits/stdc++.h>
using namespace std;

struct{
	long long l,r;
	char c;
}st[200005];

void solve(){
	int n;
	cin>>n;
	string s;
	int len=0;
	long long z=0,ans=0;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a>>st[i].c;
		st[i].l=z+1;
		z+=a;
		st[i].r=z;
		len++;
	}
	int j=len;
	for(int i=1;i<len;i++){
		long long il=z-st[i].r+1,ir=z-st[i].l+1;
		if(ir<=z-z/2) break;
		if(il<=z-z/2) il=z-z/2+1;
		while(1){
			if(st[j].l<=il){
				if(st[i].c!=st[j].c){
					ans+=ir-il+1;
				}
				break;
			}else{
				if(st[i].c!=st[j].c){
					ans+=ir-st[j].l+1;
				} 
				ir=st[j].l-1;
				j--;
			}
		}
	}
	cout<<ans;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
