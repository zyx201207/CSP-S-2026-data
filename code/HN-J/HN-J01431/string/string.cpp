#include<bits/stdc++.h>
using namespace std;
struct tion{
	long long val;
	char s;
}a[200005];
int n,tot;
long long ans;
long long tong[133];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		char u;
		int cnt;
		cin>>cnt>>u;
		tong[u]+=cnt;
	}
	for(int i=97;i<=122;i++){
		if(tong[i]){
			tot++;
			a[tot].val=tong[i];
			a[tot].s=char(i);
		}
	}
	n=tot;
	int l=1,r=n;
	long long x=a[1].val,y=a[n].val;
	char b=a[1].s,c=a[n].s;
	while(l<=r){
		if(b==c){
			if(x>y){
				ans+=(x-y);
				x=a[l+1].val-(x-y);
				b=a[l+1].s;
				l++;
				r--;
				y=a[r].val;
				c=a[r].s;
			}
			else{
				ans+=(y-x);
				y=a[r-1].val-(y-x);
				c=a[r-1].s;
				l++;
				r--;
				x=a[l].val;
				b=a[l].s;
			}
			continue;
		}
		if(x>y){
			ans+=y;
			x-=y;
			r--;
			l++;
			y=a[r].val;
			c=a[r].s;
		}
		else{
			ans+=x;
			y-=x;
			r--;
			l++;
			x=a[l].val;
			b=a[l].s;
		}
	}
	cout<<ans;
	return 0;
}

