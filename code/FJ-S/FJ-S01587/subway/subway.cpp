//T2 版本1   3：22开始  5:05结束  60dps 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10,M=2e4+5;
ll read(){
	ll a=0,f=1;
	char c=getchar();
	while (c<'0' or c>'9'){
		if (c=='-')f=-1;
		c=getchar();
	}while (c>='0' and c<='9'){
		a=a*10+c-48;
		c=getchar();
	}return a*f;
}
ll n,m,d,q,c,t;//前五个同题面，t表示零时答案 
ll qs,qz;
int w[M],k[505][N];
bool vk[505][M];//第i条线是否通过第j个点？ 
ll dtk[M][505];//第i个点到第j条线的时间  
ll dis[505][505];//flord最短路 
ll tu,tt,mint=1e9+7;
vector<int>dtk2[M];//该地铁口能够到达的地铁线 
bool flag=0;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();//问号,应该是方便暴力或分讨吧 
	n=read();m=read();d=read();q=read();
	memset(dtk,0x3f,sizeof dtk);//全为极大值~ 
	memset(dis,0x3f,sizeof dis);//全为极大值~ 
	
	for (int i=1;i<=m;i++)w[i]=read();
	 
	for (int i=1;i<=n;i++){
		k[i][0]=read();
		for (int j=1;j<=k[i][0];j++){
			tu=read();tt=read();
			k[i][j]=tu;
			dtk[tu][i]=tt; //tu点到i号线站台的时间为tt 
			if (!vk[i][tu])dtk2[tu].push_back(i); 
			vk[i][tu]=1;//i号线经过tu点
		}
	}
	//计算线与线之间的直连最短步行时间 
	for (int i=1;i<=n;i++){//起始线 
		for (int g=1;g<=n;g++){//终点线
			for (int j=1;j<=k[i][0];j++){//中转站 
				if (i==g)dis[i][g]=0;
				dis[i][g]=min(dis[i][g],
				(ll)dtk[k[i][j]][i]+dtk[k[i][j]][g]);
			}
		}
	}//先暴力建边吧
	
	for (int g=1;g<=n;g++){//任意两条线之间的最短 
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (i==j)dis[i][j]=0;
				dis[i][j]=min(dis[i][j],dis[i][g]+dis[g][j]);
			}
		}
	}

	for (int i=1;i<=q;i++){//问题数 
		mint=1e9+7;flag=0;
		qs=read();qz=read();
		t=w[qs]+w[qz];//进站和出站的时间不可避免 
		for (int j=1;j<=n;j++){
			if (vk[j][qs] and vk[j][qz]){//不考虑换线
				flag=1;
				mint=min(mint,dtk[qs][j]+dtk[qz][j]);
			}
		}
		if (flag==1){cout<<t+mint<<endl;continue;}
		
		for (int j:dtk2[qs]){
			for (int g:dtk2[qz]){
				mint=min((ll)mint,
				(dtk[qs][j]+dtk[qz][g]+dis[j][g]));
			}
		}
		cout<<t+mint<<endl;
	}
	return 0;
}
/*
图论，最短路问题
对于这个有趣的多测
我们考虑同起点的先测试吧，算一个小优化嗯 
*/
