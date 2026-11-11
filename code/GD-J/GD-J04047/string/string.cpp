#include<bits/stdc++.h>
using namespace std;
int n,a[200050],f=0;
long long s,l,ll,ans,la,r,rr,rrr;//l左遍历到第l段 ll第l段的第ll个 la遍历到第几个 ans答案 
char b[200050];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		s+=a[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	long long ss=s;
	if(s%2==0)f=1;
	s=s/2+1;
	if(a[n]>ss-s+f){
		rr=ss-s+f;
		rrr=rr;
		r=n;
	}else{
		r=n;
		rr=a[n];
		rrr=rr;
	}
	while(1){
		l++;
		if(ll+a[l]>s){
			la=s-1-ll;
			ll=s-1;
		}else{
			ll+=a[l];
			la=a[l];
		}
		while(1){
			if(b[l]!=b[r]){
				if(la>=rr){
					//cout<<rr<<" "<<la<<" "<<r<<" "<<rrr<<endl;
					ans+=rr; 
					la-=rr;
					r--;
					if(rrr+a[r]>ss-s+f){
						rr=ss-s+f-rrr;
						rrr=ss-s+f;
					}else{
						rr=a[r];
						rrr+=a[r];
					}
				}else{
					ans+=la;
					rr-=la;
				}
			}else{
				if(la>=rr){
					la-=rr;
					r--;
					if(rrr+a[r]>ss-s+f){
						rr=ss-s+f-rrr;
						rrr=ss-s+f;
					}else{
						rr=a[r];
						rrr+=a[r];
					}
				}else{
					rr-=la;
				}
			}
			if(!la||!rr)break;
		}
		if(ll==s-1)break;
	}
	cout<<ans;
	return 0;
}
