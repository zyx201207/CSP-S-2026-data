#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,ans;
int a[N];
struct node{
	int sum,w,id;
	bool operator < (const node b)const{
		if(sum==b.sum) return w<b.w;
		return sum<b.sum;
	}
};
priority_queue<node> q;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
/*每个水晶只加不减，要能量相同的尽可能多，故尽可能大但次数不超过m 
选相同的多的且尽量较大的作为参考值，对比自己小的进行操作，
如果以下一个的能量作为参考值时的总数比当前的小，那么下一个一定不会更优，否则下一个更优*/
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	a[n+1]=1e12+5;
	sort(a+1,a+n+1);
	int now=a[1],s=1;
	for(int i=2;i<=n+1;i++){
		if(a[i]==now) s++;
		else{
			q.push({s,now,i-s});
			now=a[i];
			s=1;
		}
	}
	while(!q.empty()){
		int mm=m;
		int w=q.top().w;
		s=q.top().sum;
		int i=q.top().id-1;
		q.pop();
		for(;i>=1;i--){
			int cha=w-a[i];
			if(mm-cha>=0) s++,mm-=cha;
			else break;
		}
		ans=max(ans,s);
	}
	cout<<ans<<'\n';
	return 0;
}
//5 8
//-3 -1 2 2 7

