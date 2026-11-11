#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+8;
struct p{
	ll a;
	char b;
};
p a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].a>>a[i].b;
	}
	ll l=0,r=n-1;
	long long ans=0,cnt1=0,cnt2=0;
	while(l<r){
		if(a[l].b!=a[r].b){
			if(a[l].a>a[r].a){
				cnt2+=a[r].a;
				ans+=a[r].a;
				a[l].a-=a[r].a;
				r--;
			}else{
				cnt1+=a[l].a;
				ans+=a[l].a;
				a[r].a-=a[l].a;
				l++;
			}
		}else{
			if(a[l].a>a[r].a){
				cnt2+=a[r].a;
				a[l].a-=a[r].a;
				r--;
			}else{
				cnt1+=a[l].a;
				a[r].a-=a[l].a;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
