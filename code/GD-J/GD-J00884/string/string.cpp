#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
struct node{
	ll l,r;
	char c;
}a[N];
ll b[N];
char c[N];
void solve(){
	int n;
	cin>>n;
	ll cnt=0;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>c[i];
		cnt+=b[i];
	}
	if(cnt==1) {
		cout<<0<<endl;
		return ;
	}
	ll lr=0,k=0;
	if(cnt&1){
		for(int i=1;i<=n;i++){
			lr++;
			if(lr<=cnt/2 && lr+b[i]-1>cnt/2){
				a[++k].l=lr,a[k].r=cnt/2,a[k].c=c[i];
				if(lr+b[i]-1>cnt/2+1) a[++k].l=cnt/2+2,a[k].r=lr+b[i]-1,a[k].c=c[i];
			}
			else a[++k].l=lr,a[k].r=lr+b[i]-1,a[k].c=c[i];
			lr+=b[i]-1;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			lr++;
			if(lr<=cnt/2 && lr+b[i]-1>cnt/2){
				a[++k].l=lr,a[k].r=cnt/2,a[k].c=c[i];
				a[++k].l=cnt/2+1,a[k].r=lr+b[i]-1,a[k].c=c[i];
			}
			else a[++k].l=lr,a[k].r=lr+b[i]-1,a[k].c=c[i];
			lr+=b[i]-1;
		}
	}
//	for(int i=1;i<=k;i++) cout<<a[i].l<<" "<<a[i].r<<" "<<a[i].c<<endl;
	ll l=1,r=cnt;
	ll i=1,j=k;
	ll ans=0;
	while(i<=j){
		ll o=0,len=0;
		if(a[i].r-l+1>r-a[j].l+1){
			o=1;
			len=r-a[j].l+1;
		}
		else if(a[i].r-l+1<r-a[j].l+1){
			o=2;
			len=a[i].r-l+1;
		}
		else o=3,len=a[i].r-l+1;
		//cout<<i<<" "<<j<<" "<<l<<" "<<r<<" "<<o<<" "<<len<<endl;
		if(a[i].c!=a[j].c){
			ans+=len;
		}
		l+=len,r-=len;
		if(o==1) j--;
		else if(o==2) i++;
		else j--,i++;
	}
	cout<<ans<<endl;
	
	return ;
}
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
	return 0;
} 
