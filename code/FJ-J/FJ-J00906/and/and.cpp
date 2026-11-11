#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int val,num;
}a[200005];
int s1[200005],s2[200005];
int num(int x){
	int cnt=0;
	while(x){
		cnt+=x&1;
		x>>=1;
	}
	return cnt;
}
bool num2(int x){
	bool cnt=0;
	while(x){
		cnt=!(x&1)|cnt;
		x>>=1;
	}
	return cnt;
}
bool check(int x){
	int ans=2147483647;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(x|a[i].val){
			ans&=a[i].val;
		}
	} 
	return ans==x;
}
int binary_search(int l,int r){
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return r;
}
bool cmp(node a,node b){
	return a.num>b.num;
}
int ans15=0;
void dfs(int p,int cnt,int sum){
	if(cnt==m){
		ans15=max(ans15,sum);
		return;
	}
	if(p>n)return;
	dfs(p+1,cnt,sum);
	dfs(p+1,cnt+1,sum&a[p].val);
}
bool fa=1,fb=1;
int cnt41=0,cnt42=0,cnt43=0,cnt44=0; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxn=0,andall=2147483647;
	for(int i=1;i<=n;i++){
		cin>>a[i].val;
		a[i].num=num(a[i].val);
		maxn=max(a[i].val,maxn);
		andall&=a[i].val;
		if(num2(a[i].val)){
			fa=0;
		}
		if(a[i].val!=i-1){
			fb=0;
		}
		if(a[i].val==1)cnt41++;
		if(a[i].val==2)cnt42++;
		if(a[i].val==3)cnt43++;
		if(a[i].val==4)cnt44++;
	}
	if(m==1){
		cout<<maxn<<'\n';
		return 0;
	}
	if(m==n){
		cout<<andall<<'\n';
		return 0;
	}
	if(m==2){
		int ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i].val&a[j].val);
			}
		}
		cout<<ans<<'\n';
		return 0;
	}
	if(n<=20){
		dfs(1,0,2147483647);
		cout<<ans15<<'\n';
		return 0;
	}
	if(m==n-1){
		s1[0]=2147483647;
		s2[n+1]=2147483647;
		s1[1]=a[1].val,s2[n]=a[n].val;
		for(int i=2;i<=n;i++){
			s1[i]=s1[i-1]&a[i].val;
		}
		for(int i=n-1;i>=1;i--){
			s2[i]=s2[i+1]&a[i].val;
		}
		int ansn1=0;
		for(int i=1;i<=n;i++){
			ansn1=max(ansn1,s1[i-1]&s2[i+1]);
		}
		cout<<ansn1<<'\n';
		return 0;
	}
	if(fa){
		sort(a+1,a+1+n,cmp);
		cout<<a[m].val<<'\n';
		return 0;
	}
	if(fb&&!num2(n-1)){
		cout<<n-m-1<<'\n';
		return 0;
	}
	if(maxn<=4){
		if(cnt44>=m){
			cout<<4<<'\n';
		}else if(cnt43>=m){
			cout<<3<<'\n';
		}else if(cnt42>=m){
			cout<<2<<'\n';
		}else if(cnt41>=m){
			cout<<1<<'\n';
		} 
		return 0;
	}
	cout<<0;
	return 0;
}

