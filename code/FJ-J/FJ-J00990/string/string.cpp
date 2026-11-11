#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+5;

struct node{
	int r;
	string s;
}a[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	LL ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].r>>a[i].s;
	}
	int l=1,r=a[n].r,ll=1,rr=n;
	while(ll<rr){
		if(a[ll].s!=a[rr].s){
			if(a[ll].r-l+1<r){
				ans=ans+a[ll].r-l+1;
				r=r-(a[ll].r-l+1);
				ll++;
				l=1;
			}else{
				ans+=r;
				l+=r;
				rr--;
				r=a[rr].r;
			}
		}else{
			if(a[ll].r-l+1<r){
				r=r-(a[ll].r-l+1);
				ll++;
				l=1;
			}else{
				l+=r;
				rr--;
				r=a[rr].r;
			}
		}
		
	}
	cout<<ans;
	printf("\n");
	return 0;
}

