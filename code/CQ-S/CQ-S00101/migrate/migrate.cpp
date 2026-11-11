#include<bits/stdc++.h>
using namespace std;
//#define int long long
int n,nxt[2000005],cnt[2000005],cnt2[2000005];
long long a[2000005],d;
void solve1(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	long long ans=0;
	int r=1;
	for(int i=1;i<=n;i++){
		while(r<=n&&a[r]-a[i]<=d)r++;
		nxt[i]=r-1;
	}
//	for(int i=1;i<=n;i++)cout<<nxt[i]<<' ';
//	cout<<'\n';
	for(int i=1;i<=n;i++)cnt[i]=cnt2[i]=0;
	for(int i=n;i>=1;i--){
		if(nxt[i]==i)continue;
		if(nxt[i]==i+1)cnt[i]=1+cnt[nxt[i]],cnt2[i]=cnt2[nxt[i]];
		else{
			int p1=nxt[i],p2=p1-1,p3=p1-2;
			cnt[i]=p1-i;
			if(nxt[p1]!=p1){
				int r=nxt[p1],l=nxt[p2];
				cnt[i]+=(r-l)+cnt[r];
			}else continue;
			if(p2==i+1){
				int r1=nxt[p2],r2=nxt[p1];
				if(r1==r2)cnt2[i]=r2-p1+cnt[r2];
				else cnt2[i]=r1-p1+cnt2[p1];
			}else{
				int r1=nxt[p3],r2=nxt[p2],r3=nxt[p1];
				if(r1==r2&&r3==r2)continue;
				cnt2[i]=r2-r1;
				if(r3==r2)cnt2[i]+=cnt[r3];
				else if(r2+1==r3){
					cnt2[i]+=cnt2[r3];
				}else{
					cnt2[i]+=cnt2[p1];
				}
				 
			}
		}
	//	cout<<i<<" "<<cnt[i]<<" "<<cnt2[i]<<"\n";
		ans+=cnt2[i];
	}
	//cout<<'\n';
	cout<<ans<<'\n';
}
//-3 0 1 2 3 4
//6 4
//-3 : 2,
int dp[5005];
//[5005]; 
void solve2(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	long long ans=0;
	for(int i=1;i<=n;i++){
		int l=i;cnt[i]=1;dp[i]=0;
		for(int j=i+1;j<=n;j++){
			while(a[j]-a[l]>d){
			l++;//cout<<l<<'\n';
			}
		//	cout<<l<<"p "<<j<<" "<<a[j]-a[l]<<'\n';
		//	cout<<"wjj\n";
			if(j==l){
			//	dp[j]=;cnt[j]=1;
				break;
			}
			dp[j]=dp[l]+1;cnt[j]=0;
			for(int k=l;k<=min(l+2,j-1);k++){
				if(dp[k]==dp[l])cnt[j]+=cnt[k];
				else break;
			//	cout<<"loop\n";
			}
			if(cnt[j]==2){
				ans++;
			//	cout<<i<<" "<<j<<'\n';
			}
		}
	//	cout<<"wolv\n";
	}

	cout<<ans<<'\n';
}
signed main(){
	//printf()
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T,cid;cin>>cid>>T;
	if(cid<=14&&cid>=13)while(T--)solve1();
	else if(cid<=10)while(T--)solve2();
	return 0;
}
/*
双难以分析喵。
首先往回跳完全禁止。
不难发现，只考虑可以跳到的最右两个。
接着发现如果你选次优，连下一个次优都跳不到的话那就不必要了。
接着我们发现，这样的条件刻画太宽泛。我们可以用最多单个点刻画出问题吗?
考虑容斥成不满足条件的。 
我们称一个点有多路是这样结构。
不会是，这样的结构前提下，满足区间限制的点的数量吧。
让我手玩。
让我们整理思路，我们要递归解决问题。
考虑从后往前地扫描线，维护多路的点。
wow，我不会会了吧。 
哦是恰好啊。 没关系现在还有2.5h
好的我应该会刻画了。 妈的假了。
哎，学了两年还是不如初二的分吗？553501我可真是一头128。
 与初三的不同在于这次不会挂了吧。吗？ 
 这个T4，连多项式都不会啊。好像只会15pts？
 难办。别急有一等就可以NOIP稳一点。
 感觉这个题我能刻画出来啊。
 首先特判掉所有只要两步的。
 然后这个结构如何去描述呢？ 
 就是不好做啊。好不甘心，感觉明明能做出来的。
只差刻画出只有一条路径的情况了。 
 
*/
