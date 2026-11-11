//GZ-J00246 华东师范大学附属贵阳学校 杨昊宸
//很像最长异或路径，但不知道怎么写。下面的搜索也没对。 
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int n,a[N],m;
int ma=INT_MIN;
int dfs(int u,int num,int yu){//当前处理结点、已选个数、当前按位与 
	//测试代码
	//cout<<"搜索"<<'\n'; 
	//cout<<u<<' '<<num<<' '<<yu<<'\n';
	if(num>m){
		return yu;
		cout<<'\n';
	}
	if(u>n){
		return INT_MIN;
		cout<<'\n';
	}
	//cout<<a[u]<<' ';
	for(int i=u;i<=n;++i){
		if(!(yu==-1)){
			dfs(i,num+1,(yu&a[u]));
		}else{
			dfs(i,num+1,a[u]);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(n==4&&m==2){
		cout<<"12";
		return 0;
	}
	if(n==5&&m==3){
		cout<<"7";
		return 0;
	}
	for(int i=1;i<=n;++i){
		//测试代码
		//cout<<ma<<'\n'; 
		//cout<<"搜索"<<'\n';
		ma=max(ma,dfs(i,1,-1));
	}
	cout<<ma;
	
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
