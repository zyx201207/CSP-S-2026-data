#include<bits/stdc++.h> 
using namespace std;
#define int long long
const int maxn=2e5+2;
struct str{
	int a;
	char c;
}st[maxn];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int cnt=0;
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>st[i].a>>st[i].c;
	int k=n-1,i=0;
	while(i<k){
		if(st[i].a>st[k].a){
			if(st[i].c!=st[k].c) cnt+=st[k].a;
			st[i].a-=st[k].a;
			st[k].a=0;
			k--;
		}
		if(st[i].a==st[k].a){
			if(st[i].c!=st[k].c) cnt+=st[k].a;
			st[i].a=0;
			st[k].a=0;
			k--;
			i++;
		}
		if(st[i].a<st[k].a){
			if(st[i].c!=st[k].c) cnt+=st[i].a;
			st[k].a-=st[i].a;
			st[i].a=0;
			i++;
		}
	}
	cout<<cnt;
	return 0;
}
