#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N=2e5+5;
ll n;
ll len[N],colr[N];
void jisuan(ll);
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	ll tot=0;
	for(ll i=1;i<=n;i++){
		cin>>len[i];
		char c;
		cin>>c;
		colr[i]=c-'a';
		tot+=len[i]; 
	}
	jisuan(tot);
	
	return 0;
} 
void jisuan(ll tot){
	ll cnt=0,mid=(tot>>1)+(tot&1);
	ll sed1=0,sed2=0;
	for(ll i=1;i<=n;i++){
		if(cnt+len[i]>=mid){
			sed1=i,sed2=mid-cnt;
			break;
		}
		else cnt+=len[i];
	}
	//cout<<tot<<" "<<mid<<" "<<sed1<<" "<<sed2<<endl;
	ll p1=sed1,p2=sed1;
	ll num1=sed2-(tot&1),num2=len[sed1]-sed2;
	ll colr1=colr[sed1],colr2=colr[sed1];
	ll ans=0;
	while(p1>0&&p2<=n){
		if(num2==num1){
			if(colr1!=colr2) ans+=num1;
			num1=len[--p1],num2=len[++p2];
			colr1=colr[p1],colr2=colr[p2];
		}
		if(num2>num1){
			if(colr1!=colr2) ans+=num1;
			num2-=num1;
			num1=len[--p1],colr1=colr[p1];
		}
		else {
			if(colr1!=colr2) ans+=num2;
			num1-=num2;
			num2=len[++p2],colr2=colr[p2];
		}
	} 
	
	cout<<ans;
}
