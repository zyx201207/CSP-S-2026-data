#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50005;
//n=水晶数量; m=操作次数 
long long n,m;
//energy[i]=第i块水晶的能量值 
long long energy[MAXN];

int main(){
	//规定输入输出 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	//输入 
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>energy[i];
	}
	
	//设置临时变量
	long long min_energy=9e15+15;//开到趋近于无穷大 
	long long will_do=m;
	 
	//开始进行水晶升能操作
	while(will_do>0){//以操作次数为限制条件 
		//第一步：找到最小能量值 
		min_energy=5e12+9;
		for(long long i=0;i<n;i++){
			if(energy[i]<min_energy){
				min_energy=energy[i];
			}
		} 
		
		//对最小能量值的水晶进行一次升能操作 
		for(long long i=0;i<n;i++){
			if(energy[i]==min_energy){
				energy[i]+=1;//这里没有升能品质的区分----最简单的点 
				will_do--;//升一次，少一次 
			}
		}
	}	
	
	//操作次数达到上限后，开始判断其中相等能量值的水晶的最大个数 
	long long max_num=0;//记录最大数量 
	
	for(long long i=0;i<n;i++){
		long long ex_energy=energy[i];//把每一个水晶的能量值都判断一次 
		long long num=0;//临时存储 

		for(long long j=0;j<n;j++){
			if(energy[j]==ex_energy){//判断能量水晶的能量值是否相等 
				num++;//等能量水晶计数 
			}
		}
		
		//比较num和max_num的大小 
		if(num>=max_num){
			max_num=num;
		}
	}
	
	cout<<max_num<<endl;
	return 0;
}
