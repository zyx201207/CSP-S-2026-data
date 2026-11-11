#include<bits/stdc++.h>
using namespace std;
//给定一个n<500000,m<10^18,a<10^12时间复杂度O(n log n/long n/n)才不烧心
//让你求最大合成数
//样例分析1
//5 5
//1 2 4 8 9
//思路先排序后前缀
//1 2 4 1
//从头开始加1与2差1与3差2+1
//分配发现可以
//开始合并1-3要1+(1+2),2-4要2+4+4舍去,3-5要4+1+1舍去
//所以答案为3
//样例2
//5 8
//-3 -1 2 2 7
//2 3 0 5
//8 3 10
//8
//所以答案为4
//怎么做？
//首先前缀和过去如果2个差值大于m直接删除变成2列然后循环i个的算差值大直接设为false如果扫到false断开不再扫
//更改方法用fa来记录这样方便记录
//每次记录最大值
//样例有坑排序好了这样容易死
long long n,m,ans=1;//不开longlong见祖宗
long long a[500010],cha[500010];
bool flag[500010];
long long fa[500010];
int main(){
	freopen("crystal.in","r",stdin);
	ios::sync_with_stdio(false);//加速防爆
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;//输入
	for(int i=1;i<=n;i++){
		flag[i]=true;
		cin>>a[i];
	}
	for(int i=1;i<=n-1;i++){
		long long c=a[i+1]-a[i];
		cha[i]=c;
		fa[i]=c;
		if(c>m){
			flag[i]=false;//差值过大
		}
	}
	for(int i=1;i<=n-1;i++){//需要优化剪枝
		int maxx=0;//记录最大合并数
		long long he=0,ffa;//记录差值之和
	//	cout<<"@";
		for(int j=i;j<=n;j++){
			maxx++;//增加合并值
			for(int k=2;k<=j;k++){
				he+=cha[k];//计算差值
	//			cout<<he<<"&&"<<endl;
			}
			if(he>m){//剪枝
	//			cout<<maxx<<" "<<he<<endl;
				if(ans<maxx||flag[j]==false){
					ans=maxx;
				}
				break;
			}
		}
	}
	cout<<ans;//完结撒花大概会爆
	freopen("crystal.out","w",stdout);
	return 0;
}