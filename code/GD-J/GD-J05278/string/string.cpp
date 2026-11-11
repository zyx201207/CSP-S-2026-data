#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
struct node{
	ll p;
	char q;
}a[N];
ll n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie();
	cout.tie();
	cin>>n;
	ll maxn=0;
	for(int i=0;i<n;i++){
		cin>>a[i].p>>a[i].q;
		maxn+=a[i].p;
	}
	ll left=0,right=n-1;
	ll ans=0;
	while(right-left>1){
		if(a[right].q!=a[left].q){
			ll kkk=min(a[left].p,a[right].p);
			a[left].p-=kkk;
			a[right].p-=kkk;
			if(a[left].p==0 && a[right].p==0){
				left++;
				right--;
			}else if(a[left].p==0){
				left++;
			}else{
				right--;
			}
			ans+=kkk;
		}else{
			ll kkk=min(a[left].p,a[right].p);
			a[left].p-=kkk;
			a[right].p-=kkk;
			if(a[left].p==0 && a[right].p==0){
				left++;
				right--;
			}else if(a[left].p==0){
				left++;
			}else{
				right--;
			}
		}
	}
	if(a[left].q!=a[right].q){
		ans+=min(a[left].p,a[right].p);
	}
	cout<<ans;
}
