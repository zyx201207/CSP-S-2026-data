#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n,m;
int a[200005];
/////////////////////////////////when you <=20, you can
int dfs_ans=0;
void dfs(int last,int selected,int tot){
//	cout<<"dfs("<<last<<","<<selected<<","<<tot<<")\n";
	if(tot<dfs_ans)return;
	if(selected==m){
		dfs_ans=max(dfs_ans,tot);
		return;
	}
	for(int i=last+1; i<=n; ++i){
		dfs(i,selected+1,(tot&a[i]));
	}
} 
/*
5 3
31 3 1 15 7
*/
/////////////////////////////////11-12
int s[200005],sf[200005];
///////////////////////////////// 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	if(m==1){
		int maxx=0;
		for(int i=1; i<=n; ++i){
			int x; cin>>x;
			maxx=max(maxx,x);
		}
		cout<<maxx;
		return 0;
	}
	if(m==n){
		int sum; cin>>sum;
		for(int i=2; i<=n; ++i){
			int x; cin>>x;
			sum=(sum&x);
		}
		cout<<sum;
		return 0;
	}
	if(n<=20){
		for(int i=1; i<=n; ++i){
			cin>>a[i];
		}
		dfs(0,0,1073741823);
		cout<<dfs_ans;
		return 0;
	}
	if(m==2&&n<=2000){
		int maxx=0;
		for(int i=1; i<=n; ++i){
			cin>>a[i];
		}
		for(int i=1; i<=n; ++i){
			for(int j=i+1; j<=n; ++j){
				maxx=max(maxx,(a[i]&a[j]));
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==n-1){
		s[0]=sf[n+1]=1073741823;
		for(int i=1; i<=n; ++i){
			cin>>a[i];
			s[i]=s[i-1]&a[i];
		}
		for(int i=n; i>=1; --i){
			sf[i]=sf[i+1]&a[i];
		}
		int maxx=0;
		for(int i=1; i<=n; ++i){
			maxx=max(maxx,(s[i-1]&sf[i+1]));
		}
		cout<<maxx;
		return 0;
	}
	bool only4=1;
	for(int i=1; i<=n; ++i){
		cin>>a[i];
		if(a[i]>4)only4=0;
	}
	if(only4){
		int asd[5];
		for(int i=1; i<=n; ++i) asd[a[i]]++;
		if(asd[4]>=m)cout<<4;
		else if(asd[3]>=m)cout<<3;
		else if(asd[2]+asd[3]>=m)cout<<2;
		else if(asd[1]+asd[3]>=m)cout<<1;
		else cout<<0;
		return 0;
	} 
	dfs(0,0,1073741823);
	cout<<dfs_ans;
}
/*
首先上面那堆分支应该可以拿70分
*/
/*
《岳记楼阳》 
庆历四年春滕子， 
京谪守巴陵郡越， 
明年政通人和百废具， 
兴乃重修岳， 
阳楼增其旧制刻唐， 
贤今人诗赋于其上属予作文以， 
记之予观夫巴， 
陵胜状在洞庭一湖衔， 
远山吞长江浩， 
浩汤汤横无际涯朝晖夕， 
阴气象万千此则岳， 
阳楼之大观也前人之， 
述备矣然则北通， 
巫峡南极潇湘迁客骚人多， 
会于此览物之， 
情得无异乎 
*/








































//

