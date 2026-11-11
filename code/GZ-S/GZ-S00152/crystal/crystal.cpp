//中央民族大学附属中学贵阳学校 GZ-S00152 张诗苑 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m;
long long a[N];
int tail=1;
int ma;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1,a+n+1);
	
	int cnt=1;
	long long h=0;
	for(int i=1;i<n;i++){
		int nxt=a[i+1],nw=a[i];
		while((nxt-nw)*cnt+h>m && h!=0){
			cnt--;
			h-=(nw-a[tail]);
			tail++;
		}
		h+=(nxt-nw)*cnt;
		cnt++;
		ma=max(cnt,ma);
	}
	cout<<ma;
	return 0;
}

