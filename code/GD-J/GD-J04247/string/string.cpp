#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200010],sum,t,cnt,ans,pos;
char c[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	t=(sum+1)/2;
	for(int i=1;i<=n;i++){
		cnt+=a[i];
		pos=i;
		if(cnt>=t) break;
	}
	if(sum%2==0){
		int r=cnt-t,l=a[pos]-cnt+t;
		int lpos,rpos;
		if(l>r){
			lpos=pos;
			rpos=pos+1;
			a[lpos]-=2*r;
		}
		else if(l<r){
			lpos=pos-1;
			rpos=pos;
			a[rpos]-=2*l;
		}
		else{
			a[pos]=0;
			lpos=pos-1;
			rpos=pos+1;
		}
		while(lpos>=1||rpos<=n){
			if(a[lpos]>a[rpos]){
				if(c[lpos]!=c[rpos]) ans+=a[rpos];
				a[lpos]-=a[rpos];
				rpos++;
			}
			else if(a[lpos]<a[rpos]){
				if(c[lpos]!=c[rpos]) ans+=a[lpos];
				a[rpos]-=a[lpos];
				lpos--;
			}
			else{
				if(c[lpos]!=c[rpos]) ans+=a[rpos];
				a[lpos]=a[rpos]=0;
				lpos--;
				rpos++;
			}
		}
	}
	else{
		a[pos]--;
		int r=cnt-t,l=t-cnt+a[pos];
		int lpos,rpos;
//		cout<<l<<" "<<r<<"\n";
		if(l>r){
			lpos=pos;
			rpos=pos+1;
			a[lpos]-=2*r;
		}
		else if(l<r){
			lpos=pos-1;
			rpos=pos;
			a[rpos]-=2*l;
		}
		else{
			a[pos]=0;
			lpos=pos-1;
			rpos=pos+1;
		}
//		cout<<lpos<<" "<<rpos<<"\n";
//		cout<<a[lpos]<<" "<<a[rpos];
		while(lpos>=1||rpos<=n){
			if(a[lpos]>a[rpos]){
				if(c[lpos]!=c[rpos]) ans+=a[rpos];
				a[lpos]-=a[rpos];
				rpos++;
//				cout<<lpos<<" "<<rpos;
			}
			else if(a[lpos]<a[rpos]){
				if(c[lpos]!=c[rpos]) ans+=a[lpos];
				a[rpos]-=a[lpos];
				lpos--;
			}
			else{
				if(c[lpos]!=c[rpos]) ans+=a[rpos];
				a[lpos]=a[rpos]=0;
				lpos--;
				rpos++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
