#include <iostream>
#include <cstring>
#include <string.h>
#include <string>
#include <map>
using namespace std;
#define ll long long
inline ll read(){
	ll f=1,s=0;
	char t=getchar();
	while(t<'0'||t>'9'){
		if(t=='-') f=-1;
		t=getchar();
	}
	while(t>='0'&&t<='9'){
		s=s*10+t-'0';
		t=getchar();
	}
	return f*s;
}
inline void write(ll x){
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const ll N=2e5+10;
ll ans,n,a[N],le;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i]>>c[i],le+=a[i];
	ll ind=1,l=1,r=n,sl=0,sr=0;
	while(ind<=le/2&&l<r){
		//cout<<ind<<" "<<l<<" "<<r<<" "<<sl<<" "<<sr<<" "<<ans<<endl;
		if(c[l]==c[r]){
			/*if(a[l]<a[r]){
				sl+=a[l];
				ind+=a[l],l++;
			}else if(a[l]>a[r]){
				sr+=a[r];
				ind+=a[r],r--;
			}else{
				sl+=a[l],sr+=a[r];
				ind+=a[l],l++,r--;
			}*/
			if(a[l]-(ind-sl)<a[r]-(ind-sr)){
				ind+=a[l]-(ind-sl)+1;
				sl+=a[l],l++;
			}else if(a[l]-(ind-sl)>a[r]-(ind-sr)){
				ind+=a[r]-(ind-sr)+1;
				sr+=a[r],r--;
			}else{
				ind+=a[r]-(ind-sr)+1;
				sl+=a[l],sr+=a[r];
				l++,r--;
			}
		}else{
			if(a[l]-(ind-sl)<a[r]-(ind-sr)){
				ans+=a[l]-(ind-sl)+1;
				ind+=a[l]-(ind-sl)+1;
				sl+=a[l],l++;
			}else if(a[l]-(ind-sl)>a[r]-(ind-sr)){
				ans+=a[r]-(ind-sr)+1;
				ind+=a[r]-(ind-sr)+1;
				sr+=a[r],r--;
			}else{
				ans+=a[r]-(ind-sr)+1;
				ind+=a[r]-(ind-sr)+1;
				sl+=a[l],sr+=a[r];
				l++,r--;
			}
		}
	}
	//cout<<ind<<" "<<l<<" "<<r<<" "<<sl<<" "<<sr<<" "<<ans<<endl;
	cout<<ans;
	return 0;
}
//Trick||Treat!
