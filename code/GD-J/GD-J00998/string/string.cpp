#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
long long ans;
int n;
struct sss{
	int x;
	string y;
}a[MAXN];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	int l=1,r=n,ll=a[l].x,rr=a[r].x;
	while(l<r){
		//cout<<ll<<" "<<rr<<"\n";
		if(a[l].y==a[r].y){
			if(ll<rr){
				rr-=ll;
				l++;
				ll=a[l].x;
			}
			else if(ll>rr){
				ll-=rr;
				r--;
				rr=a[r].x;
			}
			else if(ll==rr){
				l++,r--;
				ll=a[l].x,rr=a[r].x;
			}
		}
		else{
			if(ll<rr){
				ans+=ll;
				rr-=ll;
				l++;
				ll=a[l].x;
			}
			else if(ll>rr){
				ans+=rr;
				ll-=rr;
				r--;
				rr=a[r].x;
			}
			else if(ll==rr){
				ans+=ll;
				l++,r--;
				ll=a[l].x,rr=a[r].x;
			}
		}
	}
	cout<<ans;
	return 0;	
}

