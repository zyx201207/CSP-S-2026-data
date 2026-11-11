#include<bits/stdc++.h>
using namespace std;
#define int long long
//#define int __int128
const int N=1e6,A=1e18;
int n,m,a[N],sum,num,ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	//freopen(".out","r",stdin);
	//freopen(".in","w",stdout);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	stable_sort(a+1,a+n+1);
	for(int i=1,j=1;i<=n;i++)
		if(sum+(a[i]-a[i-1])*(i-j)<=m){num++;sum+=(a[i]-a[i-1])*(i-j);ans=max(ans,num);}
		else
		{
			while(sum+(a[i]-a[i-1])*(i-j)>m){sum-=a[i-1]-a[j];j++;}
			num=i-j+1;
			sum+=(a[i]-a[i-1])*(i-j);
			ans=max(ans,num);
		}
	cout<<ans;
	return 0;
}
/*
zui da zhi?er fen shua qi!!!
bro,xie cheak shi fa xian cheak shi zheng jie
zhu yi dao xuan ze de shu yi ding shi bai xu hou yi lian chuan xiang lin de shu
zhi yu wei shen me?lan de zheng le!!
ran hou shuang zhi zhen,jiu mei le
kuai qu xie!!!!
shi jian fu za du da xue shi O(n log n),ping jing zai pai xu
kong jian fa za du O(n)
*/
