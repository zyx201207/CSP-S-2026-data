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
const int maxn=510,maxm=210;
int z[maxn],t[maxm];
int n,m;
vector<int>now;
int find(int x){
	if(now.size()==0){
		return 0;
	}for(int i=0;i<now.size();i++){
		if(now[i]==x){
			return i+1;
		}
	}return 0;
} 
signed main(){
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>z[i];
	}for(int l=1;l<=n;l++){
		now.clear();
		for(int i=l;i<=n;i++){
			if(find(z[i])==0){
				now.push_back(z[i]);
			}else{
				vector<int>ne;
				for(int j:now){
					if(j==z[i]){
						break;
					}else{
						ne.push_back(j);
					}
				}now.clear();
				now=ne;
				now.push_back(z[i]);
			}
		}for(int i:now){
			t[i]+=1;
		}
	}for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}
