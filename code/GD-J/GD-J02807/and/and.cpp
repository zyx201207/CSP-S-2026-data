/*
同步流怎么关来着.?
666请输入文本
对不起 codeblocks 程序异常退出,
您的计算机剩余空间不足,程序无法自动诊断问题并向开发者发送问题报告.
我虚拟机还能炸.?神了./ 
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10;
int n,m;
int z[maxn];
void b1(){//15分 
	int ma=INT_MIN;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				continue;
			}ma=max(ma,z[i]&z[j]);
		}
	}cout<<ma;
	return ;
}void b2(){//5分 
	int ans=z[1];
	for(int i=1;i<=n;i++){
		ans&=z[i];
	}cout<<ans;
	return ;
}void b3(){//5分 
	int ma=INT_MIN;
	for(int i=1;i<=n;i++){
		ma=max(ma,z[i]);
	}cout<<ma;
	return ;
}int man,x=0;
void dfs(int dans,int d){//25分 
	if(d==n+1){
		if(x==m){
			man=max(man,dans);
		}return ;
	}dfs(dans,d+1);
	x+=1;
	dfs(dans&z[d],d+1);
	x-=1;
	return ;
}
signed main(){
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool aa=true,bb=true;
	for(int i=1;i<=n;i++){
		cin>>z[i];
		if(z[i]!=i-1){
			bb=false;
		}
	}if(m==2){
		b1();
	}else if(m==n){
		b2();
	}else if(m==1){
		b3();
	}else if(n<=20){
		int o=1;
		int p=0;
		for(int i=1;i<=23;i++){
			p+=o;
			o*=2;
		}dfs(p,1);
		cout<<man;
	}else{
		cout<<4;
	}
	return 0;
}
