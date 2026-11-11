#include<bits/stdc++.h>
using namespace std;

int n,l=1,r;
long a[200005],Lc,Rc;
char c[200005];
long long L,Ptr,ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		L+=a[i];
	}
	Lc=a[1];
	Rc=a[n];
	while(l<r){
		if(Lc>=Rc){
			if(c[l]!=c[r]) ans+=Rc;
			Lc-=Rc;
			Rc=a[--r];
		}else{
			if(c[l]!=c[r]) ans+=Lc;
			Rc-=Lc;
			Lc=a[++l];
		}
	}
	cout<<ans;
	return 0;
}
