#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
char c[N];
long long len,l[N],r[N];
long long find_l(long long x){
	int tl=1,tr=n,mid;
	while(tl<tr){
		mid=(tl+tr+1)/2;
		if(l[mid]<=x) tl=mid;
		else tr=mid-1;
	}
	return l[tl];
}
long long find_r(long long x){
	int tl=1,tr=n,mid;
	while(tl<tr){
		mid=(tl+tr)/2;
		if(r[mid]>=x) tr=mid;
		else tl=mid+1;
	}
	return r[tl];
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long a;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		l[i]=len+1;
		len=len+a;
		r[i]=len;
		cin>>c[i];
	}
	long long ll=1,rr=len,lr,rl,lenl,lenr,ans=0;
	int idl=1,idr=n;
	while(l<r){
		lr=find_r(ll);
		rl=find_l(rr);
		lenl=lr-ll+1;
		lenr=rr-rl+1;
		if(rl<lr) break;
		if(lenl>lenr){
			if(c[idl]!=c[idr]) ans=ans+lenr;
			idr--;
			ll=ll+lenr;
			rr=r[idr];
		}
		else if(lenl==lenr){
			if(c[idl]!=c[idr]) ans=ans+lenr;
			idl++,idr--;
			ll=l[idl],rr=r[idr];
		}
		else{
			if(c[idl]!=c[idr]) ans=ans+lenl;
			idl++;
			ll=l[idl];
			rr=rr-lenl;
		}
	}
	cout<<ans;
	return 0;
}
