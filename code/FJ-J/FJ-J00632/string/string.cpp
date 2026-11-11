#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010],k[200010],l,rp,lp,rq,lq,rw,lw,ans;
char c;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>k[i]>>c;
		a[i]=c-'a';
	}
	while(rp+lp!=n){
		if(lq==0){
			lp++;
			lq=k[lp];
			lw=a[lp];
		}
		if(rq==0){
			rp++;
			rq=k[n-rp+1];
			rw=a[n-rp+1];
		}
//		cout<<lp<<' '<<lq<<' '<<lw<<' '<<rp<<' '<<rq<<' '<<rw<<endl;
		if(rw!=lw){
			ans+=min(rq,lq);
		}
		if(rq<=lq){
			lq-=rq;
			rq=0;
		}else{
			rq-=lq;
			lq=0;
		}
	}
	cout<<ans;
	return 0;
}
