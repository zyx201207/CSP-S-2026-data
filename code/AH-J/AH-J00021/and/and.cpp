#include<bits/stdc++.h>
using namespace std;
int a,b,c[20010],ans=0;
void dfs(int h,int w,int s){
	if(w>b){
		ans=max(ans,h);
		return;
	}
	for(int i=s+1;i<=a-b+s;i++){
		dfs((h&c[i]),w+1,i);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
	}
	for(int i=1;i<=a;i++){
		dfs(c[i],2,i);
	}
	cout<<ans;
}



