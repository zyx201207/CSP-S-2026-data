#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200005];
struct edge{
	int id,val;
}cnt[200005];
bool cmp(edge x,edge y){
	if(x.val!=y.val)return x.val>y.val;
	return x.id>y.id;
}
bool cmp1(int x,int y){return x>y;}
int count1(int x){
	int cnt=0;
	while(x){
		//cout<<x<<endl;
		cnt++;
		x&=(x-1);
	}
	return cnt;
}
signed main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	//int p=0;
	for(int i=1;i<=n;i++){
		//cout<<count1(a[i])<<" ";
		cnt[i].val=count1(a[i]);
		cnt[i].id=a[i];
		//ans&=a[i];
	}
	sort(a+1,a+n+1,cmp1);
	sort(cnt+1,cnt+n+1,cmp);
	int ans=cnt[1].id;
	//cout<<ans<<endl;
	//cout<<count1(32768)<<" "<<count1(32767)<<endl;
	for(int i=2;i<=m;i++){
		ans&=cnt[i].id;
		//cout<<count1(ans)<<" ";
		//cout<<cnt[i].id<<" "<<cnt[i].val<<endl;
	}
	if(ans)cout<<ans;
	else cout<<a[m];
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
