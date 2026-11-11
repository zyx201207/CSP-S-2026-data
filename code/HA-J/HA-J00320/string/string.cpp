#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll n,ans;
struct asd{
	int k;
	char s;
}a[200005],b[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].k >>a[i].s ;
		b[i].k =a[i].k ;
		b[i].s =a[i].s ;
	}
	for(int i=1,j=n;i<=n,j>=1;i++,j--){
			if(a[i].s !=b[j].s ){
				ans=ans+min(a[i].k ,b[j].k );
			}
			if(a[i].k >b[j].k ){
				a[i].k =a[i].k -b[j].k ;
				b[j].k =0;
				i--;
			}
			else if(a[i].k <b[j].k ){
				b[j].k =b[j].k -a[i].k ;
				a[i].k =0;
				j++;
			}
	}
	cout<<ans/2;
	return 0;
}
