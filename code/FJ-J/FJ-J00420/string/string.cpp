#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=200010;
ll n,a[N],sum,l,r,f,tmp,ans,s,lf;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	s=sum/2;
	l=1,r=n;
	while(s>0 || f==1){
		if(f==0){
			if(lf==1) l++;
			if(s>=a[l]){
				tmp=a[l];
				s-=a[l];
				a[l]=0;
				f=1;
				lf=1;
			}
			else{
				tmp=s;
				a[l]-=s;
				s=0;
				f=1;
			}
		}
		else{
			if(tmp>=a[r]){
				tmp-=a[r];
				if(c[r]!=c[l]) ans+=a[r];
				a[r]=0;
				r--;
			}
			else{
				a[r]-=tmp;
				if(c[r]!=c[l]) ans+=tmp;
				tmp=0;
				f=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
