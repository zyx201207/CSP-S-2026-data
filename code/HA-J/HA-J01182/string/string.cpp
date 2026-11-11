#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N= 2e5+5;
int n,a[N],l,s[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >>a[i] >> c[i];
	}
	int nw = 1;
	for(int i = 2;i<=n;i++){
		if(c[i]!=c[i-1]){
			a[++nw]=a[i],c[nw]=c[i];
		}else{
			a[nw]+=a[i];
		}
	}
/*	for(int i = 1;i<=nw;i++){
		cout <<a[i] << " " <<c[i] << "\n";
	}*/
	n=nw;
	s[0]=0;
	for(int i = 1;i<=n;i++){
		s[i]=a[i]+s[i-1];
		//cout <<s[i] << " ";
	}
	l=s[n];
	int ans = 0,i,j;
	if(l%2==1){
		int mid = lower_bound(s+1,s+n+1,(l+1)/2)-s;
		int ll = (l+1)/2-s[mid-1]-1,rr=s[mid]-(l+1)/2;
		if(ll<rr){
			a[mid] -= 2*ll+1,i=mid-1,j=mid;
		}else if(ll>rr){
			a[mid]-=2*rr+1,i=mid,j=mid+1;
		}else{
			i=mid-1,j=mid+1;
		}
	}else{
		int mid = lower_bound(s+1,s+n+1,l/2)-s;
		int ll,rr;
		if(l/2==s[mid]){
			i=mid,j=mid+1;
		}else{
			ll = l/2-s[mid-1]-1,rr=s[mid]-l/2-1;
			if(ll<rr){
				a[mid] -= 2*ll+2,i=mid-1,j=mid;
			}else if(ll>rr){
				a[mid]-=2*rr+2,i=mid,j=mid+1;
			}else{
				i=mid-1,j=mid+1;
			}
		}
	}
		for(;i&&j<=n;){
			if(a[i]<a[j]){
				if(c[i]!=c[j])ans+=a[i];
				a[j]-=a[i];
				i--;
			}else{
				if(c[i]!=c[j]) ans+=a[j];
				a[i]-=a[j];
				j++;
			}
		}
	cout <<ans;
}
