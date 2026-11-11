#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
//#define int __int128
const int N=1e6,A=1e18;
int c,n,m,d,q,k,s,t,w[N];
vector<pair<int,int> >e[N];
int f[501][501];
signed main()
{
	freopen("subway.in","r",stdin);
	//freopen(".out","r",stdin);
	//freopen(".in","w",stdout);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=(i==j?0:A);
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)cin>>s>>t,e[s].push_back({i,t});
	}
	for(int o=1;o<=m;o++)
	{
		for(auto i:e[o])
			for(auto j:e[o])
				f[i.first][j.first]=min(f[i.first][j.first],i.second+j.second);
	}
	for(int o=1;o<=n;o++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][o]+f[o][j]);
	for(int o=1;o<=q;o++)
	{
		cin>>s>>t;
		int ans=A;
		for(auto i:e[s])
			for(auto j:e[t])
				ans=min(ans,f[i.first][j.first]+i.second+j.second);
		cout<<ans+w[s]+w[t]<<"\n";
	}
	return 0;
}
/*
hao nan!!!!!!!
you 5e5 ge dian,1e5 ci xun wen,Jhonson dou pao bu dong
bu dui,wo men zhu yi dao k zhi you 500,floyd dou neng pao
md,du cuo ti le,zia xian lu zhong yun xing shi bu chan sheng gong xian
wo men ke yi ba yi tiao xian lu dang zuo yi ge dian
na zen me ba zheng chang dian zhuan hua wei xian lu dian ne?
bie ji,rang wo xiang xiang
zhu yi dao d zhi you 20,dui yu mei ge zheng chang dian,ru guo ta lian jie i hao xian lu he j hao xian lu
na me i hao xian lu bian yu j hao xian lu bian zhi jian de ju li wei gai zheng chang dian dao i hao xian de ju li yu dao j hao xian de ju li zhi he
zheng chang dian zhuan hua wei le xian lu dian zhi jian de bian!!!!!!!
na cha xun zen me ban ne
wo si kao
na jiu mei ju qi dian he zhong dian lian jie de suo you xian lu,ran hou,ran hou jiu mei le
kuai qu xie!!!!!!!
shi jian fu za du da yue shi shi O(m*d^2+n^3+q*d^2),da yue 4e8
kong jian fu za du da yue shi O(m+n^2),da yue shi 7.5e5
ka chang!!!
ka bu dong QAQ
reng le
yu ji 80???
*/ 
