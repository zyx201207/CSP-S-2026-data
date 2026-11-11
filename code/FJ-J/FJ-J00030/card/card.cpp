//?pts
#include<bits/stdc++.h>
using namespace std;
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
//看数据范围决定 long long , 记得备份文件(得部分分文件)
const int N=5e5+5,M=3e5+5;
int n,m,a[N]={0},ans[M]={0},tmp;
bool b[M]={0};
int main(){
	ios::sync_with_stdio(false);//Debug(调试)要关闭
	cin.tie(nullptr);cout.tie(nullptr);
	file("card");//不要注释 freopen
	stack<int> q;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]]==1){
				if(q.top()==a[j]) q.pop();
				else{
					while(!q.empty()){
						tmp=q.top();
						q.pop();
						if(tmp==a[j]) break;
					}
				}
				b[a[j]]=0;
			}
			q.push(a[j]);b[a[j]]=1;
		}
		while(!q.empty()){
			tmp=q.top();
			q.pop();
			ans[tmp]++;
			b[tmp]=0;
		}
		for(int x=1;x<=m;x++) b[x]=0;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}


