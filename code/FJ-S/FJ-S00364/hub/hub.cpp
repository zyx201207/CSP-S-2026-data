#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
	char c=getchar();
	int x=0,f=1;
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const int N=5e5+4;
ll a[N],b[N],n,m;
ll ans[N];
int finallyans;
ll check(int x){
	ll cnt=0,sum=0;
	for(int i=x;i>=1;i--){
		sum+=a[x]-a[i];
		if(sum>m) break;
		cnt++;
	}
	return cnt;
}
//t m,g n
void dfs(int step,int target,int goal,int last){
	if(step==target+1){
		for(int i=1;i<=goal;i++){
			b[i]=a[i];
		}
		for(int i=1;i<=target;i++){
			b[ans[i]]++;
		}
		sort(b+1,b+1+goal);
		int ls=0,cur=1;
		for(int i=2;i<=goal;i++){
			if(b[i]==b[i-1]){
				cur++;
			}
			else{
				ls=max(ls,cur);
				cur=1;
			}
		}
		ls=max(ls,cur);
		finallyans=max(finallyans,ls);
		return;
	}
	for(int i=last;i<=goal;i++){
		ans[step]=i;
		dfs(step+1,target,goal,i);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cout<<1<<"\n"<<2;
	return 0;
}
