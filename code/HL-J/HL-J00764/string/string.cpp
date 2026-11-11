#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
const int maxn=2e6+5;
const int mod=1e9+7;
struct node{
	ll t;
	char ch;
}a[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;
    cin>>n;
    a[0].ch='?';
    int wei=1;
    for(int i=1;i<=n;i++){
    	ll m;
		char c;
    	cin>>m>>c;
    	if(c==a[wei-1].ch)a[wei-1].t+=m;
    	else a[wei].t=m,a[wei++].ch=c;
	}wei--;
	ll p=1,q=wei;
	ll ans=0;
	ll leftt=0;
	while(p<q){
		if(a[p].ch==a[q].ch){
			ans+=abs(a[p].t-a[q].t);
			leftt=abs(a[p].t-a[q].t);
			if(max(a[p].t,a[q].t)==a[p].t)a[p+1].t+=leftt;
			else a[q-1].t+=leftt;
		}
		else{
			ans+=min(a[p].t,a[q].t);
			leftt=abs(a[p].t-a[q].t);
			if(max(a[p].t,a[q].t)==a[p].t)a[p].t=leftt,p--;
			else a[q].t=leftt,q++;
		}
		p++,q--;
	}cout<<ans;
	return 0;
}    