#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k,num=0;
	char L[1000010]={};
	cin>>k;
	for(int i=1;i<=k;i++){
		int x;
		char y;
		cin>>x>>y;
		for(int j=1;j<=x;j++){
			num+=1;
			L[num]=y;
		}
	}
	int t=0;
	if(num%2==1){
		int shen=(num+1)/2;
		for(int i=1;i<=(num-1)/2;i++){
			if(L[shen-1]!=L[shen+1]){
				t++;
			}
		}
	}else{
		int zhuo=num/2;
		for(int i=0;i<zhuo;i++){
			if(L[zhuo-i]!=L[zhuo+i+1]){
				t++;
			}
		}
	}
	cout<<t;
} 
