#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct num{
	ll k,st;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll sum=1,n;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i].k>>a[i].c;
		a[i].st=sum;
		sum+=a[i].k;
	}
	ll l=1,r=sum-1,ql=1,qr=n,cnt=0;//ql:l的区间 qr:r的区间 
	while(ql<qr){
		if(a[ql+1].st-l<r-a[qr].st+1){
			if(a[ql].c!=a[qr].c) cnt+=a[ql+1].st-l;
			r-=a[ql+1].st-l;
			l=a[ql+1].st;
			ql++;
		}
		else if(a[ql+1].st-l>r-a[qr].st+1){
			if(a[ql].c!=a[qr].c) cnt+=r-a[qr].st+1;
			l+=r-a[qr].st+1;
			r=a[qr].st-1;
			qr--;
		}
		else{
			if(a[ql].c!=a[qr].c) cnt+=r-a[qr].st+1;
			l=a[ql+1].st;
			r=a[qr].st-1;
			ql++;
			qr--;
		}
	}
	cout<<cnt;
	return 0;
} 
