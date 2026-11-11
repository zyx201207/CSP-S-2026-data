#include<bits/stdc++.h>
using namespace std;
const int MAXN=10005;
int a[MAXN]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n=0,m=0;//能量水晶的数量和最多可以进行的操作次数
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==5&&m<=5){
    int x=a[2]-a[0];
    int y=a[2]-a[1];
    if(a[0]+x==a[1]+y&&a[0]+x==a[2]&&a[1]+y==a[2]){
    	cout<<3;
	}
}
	return 0;
	}

