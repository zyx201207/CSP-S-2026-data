#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[514514],s[514514],n,m;
//找第一个大于需要次数的 
int binary_s(int l1,int r1){
	//cout<<l1<<" "<<r1<<'\n';
	int p=a[l1];
	int l2=l1;
	int l=l1,r=r1;
	while(l<=r){
		int mid=(l+r)>>1ll;
		//cout<<mid<<" "<<s[l2]-s[mid]-p*(l2-mid)<<"\n";
		if(s[l2]-s[mid]-p*(l2-mid)>m)r=mid-1;
		else l=mid+1;
	}
	//cout<<l<<'\n';
	return l;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int t=binary_s(i,n);
		//if(t==n+1)continue;
		ans=max(ans,t-i);
	}
	cout<<ans;
	return 0;
}
//前缀和 二分 O(nlogn)
//luogu uid:1612389 
//AC 14:59
/*	
	wo yao shang mi huo
	会赢的.jpg 
	Mario&Luigi Yes Yes Yes
	Mario&Luigi Superstar Saga Skills Introduction(Bros. Attack)
	Guide:
	X:press X button
	X!:press X button quickly
	Loop[OPT](Num)do OPT Num times
	X-<:hold X button
	Mario:
	1.Splash Bros.
		A->B->A Very Easy
	2.Splash Bros. Advanced!
		A->A->B->A Can Attack mob has something on head
	3.Chopper Bros.
		A->B->A! Flame damage
	4.Chopper Bros. Advanced!
		A->A->Loop[B->A] Need Rhyme to Make More Damage
	5.idk Bros.:
		A-<->B Damage High(I forget the name)
	6.idk Bros. Advanced!
		A-<->B->A->Loop[A!&B!] Can Loot Mob's Rare Drops
	7.Fire Bros.
		A!->Loop[B](Acnt) Fire Critcal
	8.Fire Bros. Advanced!
		A!->Loop[B->A](Acnt)->A Make Debuff
	Luigi:
	1.Bounce Bros.
		B->A->B the Worst one.
	2.Bounce Bros. Advanced!
		A->B->B->A 2 Targets and Do it quickly
	3.Knockback Bros.
		B->B->A Strong.
	4.Knockback Bros. Advanced!
		B->A->B->Loop[A->B] Best One.
	5.Cyclone Bros.
		B->A!->Loop[(Choose Target)](Acnt-1) Only one Strong AoE in this game.
	6.Cyclone Bros. Advanced!
		B->A!->Loop[(Choose Target)](Acnt-1)->A->B Make Boss Dizzy
	7.Thunder Bros.
		B->B->B Only one pure AoE in this game.
	8.Thunder Bros. Advanced!
		B->A->A->B Single Target.
*/
