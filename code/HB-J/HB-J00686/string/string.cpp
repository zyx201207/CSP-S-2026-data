#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N],l,r,ans,q1,q2,mx;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==1){cout<<"0";return 0;}
	r=n+1;
	l=0;
	while(l<r){
		if(q2<q1){
		     r--;
		     q2+=a[r];
		     if(q2<=q1&&c[l]!=c[r]) ans+=a[r];
		     else if(c[l]!=c[r]&&l>=1){
				 ans+=abs(q1-q2+a[r]);
			 }
			 //cout<<ans<<" "<<r<<"\n";
			 continue;
		}
		else{
			l++;
			q1+=a[l];
			if(q1<=q2&&c[l]!=c[r]) ans+=a[l];
			else if(c[l]!=c[r]&&r<=n){
				ans+=abs(q2-q1+a[l]);
			}
			//cout<<ans<<" "<<l<<"\n";
			continue;
		}
	}
	cout<<ans;
}

