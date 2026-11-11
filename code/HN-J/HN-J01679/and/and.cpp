#include<bits/stdc++.h>
using namespace std;
int n,a[200005],box[200005],m;
bool vis[200005]={};
int maxx=-1;
void DFS(int s,int box){
	if(s>=n||box==m){
		if(box==m){
			return;
		}else return;
	}
	for(int i=0;i<n;i++){
		if(a[s]&a[i]>maxx&&vis[i]==0&&i!=s){
			//cout<<"正在对比s为"<<s<<",i为"<<i<<",的"<<a[s]<<",和"<<a[i]<<endl; 
			maxx=a[s]&a[i];
			//cout<<"计算出新的最大值"<<maxx<<"现在Box里有"<<box+1<<"个数"<<endl; 
			vis[i]=1;
			DFS(s+1,box+1);
			//DFS(s+1,box);
			vis[i]=0;
			//cout<<"创建新的DFS成功,参数为"<<s+1<<" "<<maxx<<" "<<box+1<<endl;
		}
	}
	DFS(s+1,box);
	//cout<<"没有找到最大值，原生传递下一个,本次销毁"<<endl;
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	DFS(0,0);
	cout<<maxx;
}
