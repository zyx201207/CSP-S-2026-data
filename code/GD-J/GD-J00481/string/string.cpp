#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll n;
struct note{
	ll a;
	char c;
}a[N];
ll ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ll sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c; 
		sum+=a[i].a;
	}
	ll mb=(sum+1)/2,cnt=0;
	ll l=0,r=0;
	for(int i=1;i<=n;i++){
		if(a[i].a>=mb){
			for(int j=n;j>=i+1;j--){
				a[j+1]=a[j];
			}
			n++;
			a[i+1]=a[i];
			int t=a[i].a;
			a[i].a=mb;
			a[i+1].a=t-mb;
			if(sum%2==1){
				a[i].a--;
			}
			l=i,r=i+1;
			break;
		}
		mb-=a[i].a;
	}
	while(l>=1||r<=n){
		if(a[l].a==0){
			l--;
		}else if(a[r].a==0){
			r++;
		}else if(a[r].c==a[l].c){
			int t=min(a[l].a,a[r].a);
			a[l].a-=t;
			a[r].a-=t;
		}else{
			int t=min(a[l].a,a[r].a);
			ans+=t;
			a[l].a-=t;
			a[r].a-=t;
		}
	}
	cout<<ans;
	
	return 0;
}/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
