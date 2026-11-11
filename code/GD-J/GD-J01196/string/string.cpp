#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,Size,ans;
struct node{
	int len;char c;
}a[N];
signed main(){
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].len>>a[i].c,Size+=a[i].len;
	int lS=1,rS=n;
	while(lS<rS){
		if(a[lS].len==a[rS].len){
			if(a[lS].c!=a[rS].c)ans+=a[lS].len;
			lS++,rS--;
		}
		else if(a[lS].len>a[rS].len){
			if(a[lS].c!=a[rS].c)ans+=a[rS].len;
			a[lS].len-=a[rS--].len;
		}
		else{
			if(a[lS].c!=a[rS].c)ans+=a[lS].len;
			a[rS].len-=a[lS++].len;
		}
	}
	cout<<ans;
	return 0;
} 
