#include<bits/stdc++.h>
using namespace std;
int t,n,k,ans,a[15],c;
bool vis[15];
vector<int> v[15];
int dfs2(int u,int step){
	vis[u]=true;
	if(a[u]) return step;
	int tmp=1e9;
	for(int y:v[u]) if(!vis[y]) tmp=min(tmp,dfs2(y,step+1));
	return tmp;
}
void dfs(int step,int now){
	if(step==k){
		int res=0;
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			res=max(res,dfs2(i,0));
		}
		ans=min(ans,res);
		return;
	}
	if(now>n) return;
	a[now]=true;
	dfs(step+1,now+1);
	a[now]=false;
	dfs(step,now+1);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=1e9;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(0,1);
		cout<<ans<<'\n';
	}
	return 0;
}
//12min,T1,wa
//18min,T1,O(n^2) idea
//21min,T1,O(n) idea
//26min,T1,O(n) ac 4
//29min,T1,submitted
//38min,T2,read
//52min,T2,O(n^3+n*k+q*d^2) idea
//84min,T2,O(n^3+n*k+q*d^2) finished
//99min,T2,wa on #7??
//101min checker problem T2 ac
//119min,T3,read
//120min,zzz
//I want to do something.....
//I love hrx 
//我要上迷惑行为大赏！！！！！！！！！！
//hrx我喜欢你！！！！！！！！
//freopen("subway.in","r",stdin);
//freopen("subway.in","r",stdin);
//freopen("subway.in","r",stdin);
//freopen("subway.in","r",stdin);
//freopen("subway.in","r",stdin);
//freopen("subway.in","r",stdin);
//freopen("subway.in","r",stdin);
//freopen("subway.in","r",stdin);
//freopen("subway.in","r",stdin);
//freopen("subway.in","r",stdin);
//freopen("crystal.in","r",stdin);
//freopen("crystal.in","r",stdin);
//freopen("crystal.in","r",stdin);
//freopen("crystal.in","r",stdin);
//freopen("crystal.in","r",stdin);
//freopen("crystal.in","r",stdin);
//freopen("crystal.in","r",stdin);
//freopen("crystal.in","r",stdin);
//freopen("crystal.in","r",stdin);
//freopen("crystal.in","r",stdin);
//freopen("migrate.in","r",stdin);
//freopen("migrate.in","r",stdin);
//freopen("migrate.in","r",stdin);
//freopen("migrate.in","r",stdin);
//freopen("migrate.in","r",stdin);
//freopen("migrate.in","r",stdin);
//freopen("migrate.in","r",stdin);
//freopen("migrate.in","r",stdin);
//freopen("migrate.in","r",stdin);
//freopen("migrate.in","r",stdin);
//freopen("hub.in","r",stdin);
//freopen("hub.in","r",stdin);
//freopen("hub.in","r",stdin);
//freopen("hub.in","r",stdin);
//freopen("hub.in","r",stdin);
//freopen("hub.in","r",stdin);
//freopen("hub.in","r",stdin);
//freopen("hub.in","r",stdin);
//freopen("hub.in","r",stdin);
//freopen("hub.in","r",stdin);
//无聊发篇题解吧
//T1：双指针，枚举每个起点的最大值
//T2：直接暴力显然tle。
//注意到n，d都很小，复杂度肯定和这两个东西有关。
//q很大，单次询问估计O（1）左右
//考虑floyd
//只有n可以接受立方复杂度
//把一条线路当作一个点，建图O（nm）
//floyd O（n^3)
//输出答案 ：单次询问O（d^2)枚举线路 
//总复杂度O(n^3+n*(m+k)+q*d^2) 可以接受
//T3T4都不知道 全打的暴力qwq
//这总能给我上了吧
//这行为应该够迷惑了
//众所周知，茶壶是化学教学软件
//所以...
//看上面
//如果我不小心删了的话简单说下idea吧
//就是茶壶的变量当作元素
//甚至还有原子序数显示
//都能做元素周期表了
//函数是离子组成的化合物
//结构体和类是普通化合物
//不错吧 可以在csp里学化学
//152min,T3 O(n^2) idea
//40+16=56 points
//203min,T3 O(n^2) failed
//O(n^3)
//24 points
//203min,T4 read
//204min,T4 O(2^k) idea
//15 points
// tot:239 points
//rp++
//rp++
//rp+=1e9;
//1=
//7勾
//232min,全部提交 检查ing...
//最后说一句，hrx是我的，cn别和我枪
//220299
//9999
//csp rp++
//++rp
//unsigned long long rp=0;rp--;
//不要挂分啊
//我最后的希望了
//挂一道就要退役了
//......................................................................
//祝大家也rp++
//和我一样
//还有4分钟了，写些遗言吧
//呃啊
//第三题紧急时刻wa了
//没事这分不要也罢
//还有3分钟
//检查ll，检查freopen
//还有两分钟
//检查提交，检查完整性
//还有一分钟
//不写了
//再见
//rp++