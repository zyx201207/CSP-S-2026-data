#include <bits/stdc++.h>
using namespace std;

const int N=2e9+5;

//c=测试点编号(?); t=测试组数 
int c,t;
//n=一组数据中岛屿数量; d=一组数据中海鸟的最大飞行间距 
long long n,d;
//x[i]=第i座岛屿的坐标(由题意应是y轴) 
long long x[N];

int main(){
	//规定输入输出
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	//输入操作（仅基本量c, t）
	cin>>c>>t;
	//设置参数变量
	long long now_land=1;//记录海鸟当前位置
	long long max_srength=0;//记录最长两海岛之间的距离(注意：max_strength <= d) 
	long long num=0;//记录距离相等的岛屿数量 
	
	//设置答案变量
	long long ans=0; 
	 
	//对每组数据进行"输入+处理+输出"复合操作，枚举 
	for(int i=1;i<=t;i++){
		cin>>n>>d;//输入当前组数据的岛屿数和最长飞行间距 
		for(int j=1;j<=n;j++)
			cin>>x[j];
		while(now_land!=n){
			for(int j=now_land+1;j<=n;j++){
				//由题意可知，最短路径即最少飞行次数，则用间距除以最长飞行间距获得最小数值（有余数就加一） 
				int s=x[j]-x[now_land]/d;
				if(d==1||d==x[n]-x[1])//特判当d=1或正好d=始末岛间距,永远只有一种情况 
					continue;
				else if(!(x[j]-x[now_land]>d*s&&s>=2)){
				//这种情况（x[j]-x[now_land]>d*s&&s>=2）时，由于余数永远小于d，所以会出现大于2的组合数 
					ans++;//不满足以上情况，则可以满足二项组合，即C(2,k) 
				}
			}	
		}
		
		//输出 
		cout<<ans<<endl;	
	}
		
		
	
	
	return 0;
}
