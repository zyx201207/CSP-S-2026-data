#include<iostream>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int a[n],b[n],c[m]={0},b_=0,i_=0;
	//定义 
	for(int i=0;i<n;i++){
		cin>>a[i];
	}//输入
	for(int i=1;i<n;i++){
		b[b_]=a[i-1];
		b_++;
		i_=i;
		for(int j=0;j<b_;j++){
			for(int k=0;k<b_;k++){
				if(j+1==b[k]){
					c[j]++;
				}
			}
		}
		for(int j=0;j<b_-1;j++){
			if(a[i-1]==b[j]){
				for(int k=a[i-1];k<n;k++){
					b[k]=0;
				}
				b_=0;
			}
		}//拿走 
	}//开始游戏 
	
	for(int i=0;i<i_;i++){
		cout<<c[i]<<" ";
	} 
	
	
	return 0;
} 
