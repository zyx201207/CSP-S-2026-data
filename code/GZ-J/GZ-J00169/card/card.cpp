//GZ-J00169 遵义市第一初级中学 梁悠然 
#include <iostream>
using namespace std;
int n=5;
void dfs(int u){
	if(u+1==n){
		cout<<u;
	}
	dfs(u+1);
}
int main (){
	int n,m;
	cin>>n>>m;
	dfs(n);
}

