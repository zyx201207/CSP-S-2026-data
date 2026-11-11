#include<bits/stdc++.h>
using namespace std;
int main(){
	int c,t;//c是测试点编号，t是数据组数 
	cin>>c>>t;
	int n,d;//n是岛屿数量，循环时使用n作为岛屿循环组。d是海鸟一次最多能飞行的距离，用d作为判断条件 
	int x[1145]={}; 
	int sum=0;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=0;j<n;j++){
			cin>>x[j];
			if(x[j]-x[0]<=d){
				sum = sum+1;
			}
		}
		cout<<sum/3<<endl;
	}
	return 0;
}
