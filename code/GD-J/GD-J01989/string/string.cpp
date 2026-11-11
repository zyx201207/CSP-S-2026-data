#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll n,cnt=1,ans=0;
struct stu{
	ll n;
	char a;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++,cnt++){//ÊäÈë´¦Àí 
		cin>>a[cnt].n>>a[cnt].a;
		if(a[cnt].a==a[cnt-1].a){
			a[cnt-1].n+=a[cnt].n;
			cnt--;
		}
	}
	for(ll addl=1,addr=n;addl<=addr;addl++,addr--){
		if(a[addl].n<a[addr].n){
			a[addr].n-=a[addl].n;
			if(a[addl].a!=a[addr].a)ans+=a[addl].n;
			addr++; 
		}else if(a[addl].n>a[addr].n){
			a[addl].n-=a[addr].n;
			if(a[addl].a!=a[addr].a)ans+=a[addr].n;
			addl--;
		}else{
			if(a[addl].a!=a[addr].a) ans+=a[addl].n;
		}
	}
	cout<<ans;
	return 0;
} 
