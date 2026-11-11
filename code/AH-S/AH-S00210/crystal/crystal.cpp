#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500010;
int n;
ll m;
ll a[N];
ll b[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(i==n-1){
			b[n-1]=0x0ffffffffffffffe;
		}
		else{
			b[i]=a[i+1]-a[i];
		}
	}
	ll maxcnt=0xfffffffffffffffe;
	for(int i=0;i<n-1;i++){
		ll cnt=0;
		ll nv=0;
		int j=i;
		int k=1;
		while(nv<=m&&j<n-1){
			nv+=b[j]*k;
			cnt++;
			j++;
			k++;
			//cout<<nv<<"  ";
		}maxcnt=max(cnt,maxcnt);
		//cout<<"\n";
	}cout<<maxcnt;
    return 0;
}
