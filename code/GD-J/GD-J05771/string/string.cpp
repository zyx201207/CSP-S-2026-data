#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=2e5+10;
struct node{
	ll a;
	char c;
}b[MAXN],d[MAXN];
ll n,cnt,temp,p=0,q=0,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>b[i].a>>b[i].c;
		cnt+=b[i].a;
		d[n-i-1].a=b[i].a;
		d[n-i-1].c=b[i].c;
	}
	for(int i=0;i<cnt/2;i++){
		if(b[p].c==d[q].c){
			ll temp2=min(b[p].a,d[q].a);
			b[p].a-=temp2;
			d[q].a-=temp2;
		}
		if(b[p].c!=d[q].c){
			b[p].a--;
			d[q].a--;
			ans++;
		}
		if(b[p].a<=0&&d[q].a<=0){
			p++;
			q++;
		}
		if(b[p].a<=0){
			p++;
		}
		if(d[q].a<=0){
			q++;
		}
		if(p==n-1&q==0) break;
	}
	cout<<ans<<endl;
	return 0;
}
