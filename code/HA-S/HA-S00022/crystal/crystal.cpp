#include<bits/stdc++.h>
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define int long long
//const int mod=998244353;
//const int mod=1e9+7;
const int N=5e5+5;
using namespace std;
int read(){
	int x=0;
	short f=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=x*((1<<1)+(1<<3))+c-'0';
		c=getchar();
	}
	return ((f)?(-x):(x));
}
int n,m,a[N];
//11mins past.
//it seems that everyone is coding.
//first of all,
//why does the computer can't type in Chinese?!
//let's watch the samples to find something...
//first and foremost,the correct answer is lianxude(English is so poor)
//so we can consider shuangzhizhen
//however,how can we check the answer in short time?
//qianzhuihe?
//or chafen?
//qianzhuihe!
//one day.
//time: O(n log n)
//brute force to find the left position,
//with erfen to find the right position.
//and luckily,
//we don't need __int128.
//why does my computer always changes its color?
int sum[N];
bool check(int l,int r){
	int real=sum[r]-sum[l-1];
	int aim=a[r]*(r-l+1);
	if(real+m>=aim){
//		printf("check(%d,%d)=true\n",l,r);
		return true;
	}
//	printf("check(%d,%d)=false\n",l,r);
	return false;
}
int find(int l){
	int ql=l,qr=n;
	while(ql<qr){
		int mid=rand()%(qr-ql+1)+ql;
//		printf("ql=%d,qr=%d,mid=%d\n",ql,qr,mid);
		if(check(l,mid)==true) ql=mid+1;
		else qr=mid-1;
	}
	if(check(l,ql)==true) return ql;
	return ql-1;
}
int maxn(int x,int y){
	return ((x>y)?(x):(y));
}
int ans;
int T;
//why does a crystal can has negative energy?
//electricity?
//tested.
//once I use brute force to find the right position,my answer is correct,but I will TLE.
//this code will be copied for duipai.
//then the only problem is about the erfen.
//How hot the computer room is!!!!!
//why?
//can't I write erfen?!
//nearly an hour.
//I passed all the samples!
//let's duipai.
//remember to delete the debug!!!
//it is a joke that the bf is RE,but my std is correct.
//ONE DAY,TODAY.
//58min.
//啊原来能输中文啊
//我才发现
//目测难度橙到黄，更倾向于黄
void solve(){
	n=read(),m=read();
	for(int i=1;i<=n;++i) a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
//	for(int i=1;i<=n;++i) cout<<sum[i]<<' ';
//	puts("");
//	system("pause");
	for(int l=1;l<=n;++l){
		if(n-l+1<=ans) break;
		int r=find(l);
//		int r=0;
//		for(int i=n;i>=l;--i){
//			if(check(l,i)==true){
//				r=i;
//				break;
//			}
//		}
		ans=maxn(ans,r-l+1);
	}
	cout<<ans<<'\n';
}
signed main(){
	fre("crystal")
	srand(time(0));
	T=1;
//	T=read();
	while(T--) solve();
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
/*
5 5
1 2 4 8 9
*/
//哦对了
//就在我写下这行代码的时候是10月31日
//祝你万圣节快乐!
