#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long n,m,ans;
struct P{
	long long pre,num;
}a[N];
bool cmp1(P x,P y){
	return x.num<y.num;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i].num;
	sort(a+1,a+n+1,cmp1);
	for(int i=1;i<n;i++)a[i].pre=a[i+1].num-a[i].num;
	for(int i=1;i<=n;i++){
		long long r=i;
		long long c=m,cnt=1;
		while(c>=0&&r<=n){
			if(c-cnt*a[r].pre>=0){
				c-=cnt*a[r].pre;
				cnt++;
				r++;
			}else break;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
