#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+5;
ll n,m,a[N],b[N];
bool t[N];
int main(){
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){b[n-i+1]=a[i]; }
	for(int i=1;i<=n;i++) {
		for(int j=0;j<=30;j++) {
			if(pow(2,j)==b[i]){
				t[i]=1;
				break;
			}
		}
	}
	int q=0; ll ans=pow(2,30)-1;
	for(int i=1;i<=n;i++) {
		if(t[i]==0) ans&=b[i],q++;
		if(q==m) {cout<<ans; return 0;
		}
	}
}
