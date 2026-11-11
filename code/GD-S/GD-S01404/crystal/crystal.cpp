#include <iostream>
#include <cmath>
using namespace std;
long long a[100005]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	int num=0;
	cin>>n>>m;//分别表示水晶数量、最多可操作次数
	for(int i=1;i<=n;i++){
		cin>>a[i];//表示第i颗水晶的能量值 
	}
	int mid=(n/2)+1;//表示想合成需达到的能量值 
	for(int i=1;i<=n;i++){
		if(a[i]<a[mid]&&m!=0){// 判断对应水晶能否成为合成水晶的一部分 
				a[i]++;//对应水晶能合成水晶，能量值加一
				m--;//可操作次数减一 
				num++;//合成大水晶的水晶数量 
		}
	} 
	cout<<num+1;//水晶数量+1 
	return 0;
} 
