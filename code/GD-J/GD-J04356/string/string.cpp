#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n;
int a[N];
int sum[N];
char c[N];
struct node{
	int pos1,pos2;
};
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		sum[i]=sum[i-1]+a[i];
	}
	node l,r;
	if(sum[n]==1){
		cout<<0;
		return 0;
	}
	int ans=0;
	l.pos2=sum[n]/2;
	r.pos2=sum[n]/2+1;
	if(sum[n]&1){
		r.pos2++;
	}
	l.pos1=lower_bound(sum+1,sum+n+1,l.pos2)-sum;
	r.pos1=lower_bound(sum+1,sum+n+1,r.pos2)-sum;
	l.pos2-=sum[l.pos1-1];
	r.pos2-=sum[r.pos1-1];
	while(1){
		if(l.pos1==0||r.pos1==n+1)break;
			if(c[l.pos1]==c[r.pos1]){
			if(l.pos2<=a[r.pos1]-r.pos2+1){
				r.pos2+=l.pos2;
					l.pos1--;
				l.pos2=a[l.pos1];
			}else{
				l.pos2-=(a[r.pos1]-r.pos2+1);
				r.pos1++;
				r.pos2=1;
			}
		}else{
			ans+=min(l.pos2,a[r.pos1]-r.pos2+1);
			if(l.pos2<=a[r.pos1]-r.pos2+1){
				r.pos2+=l.pos2;
				l.pos1--;
				l.pos2=a[l.pos1];
			}else{
				l.pos2-=(a[r.pos1]-r.pos2+1);
				r.pos1++;
				r.pos2=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
