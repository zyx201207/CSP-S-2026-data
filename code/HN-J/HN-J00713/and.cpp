#include<bits/stdc++.h>//气笑了，看错题耽误30min有感觉吗 
using namespace std;//逆天，这么明显的缺陷大样例没测出来！？ 
int n,m,a[214514];//甚至freopen还打错了？？ 
inline int dfs(int x,int y){
	int res=x;
	for(int i=y-1;i>=0;--i){
		int as=x|(1<<i);
		int su=0; 
		for(int j=1;j<=n;j++){
			if((a[j]&as)==as){
				su++;
			}
		}
		if(su>=m){
			return dfs(as,i);
		}
	}
	return res;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);//freopen("asd.out","w",stdout); 
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	cout << dfs(0,30);
	return 0;
}
