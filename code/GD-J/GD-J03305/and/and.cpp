#include <bits/stdc++.h>
using namespace std;
//虽然第二道题做的有点shit有点慢了
//但是第三道足够简单好吧
//思路蛮简单的 只要对二进制有基本认识就行 但是我不会stl......所以可能慢点
/*从最高位开始考虑 
计算1的数量 num<m -> 留不住的 不用管
num==m -> 直接下班
num>m -> 把 剩下的删了 继续搞
如果搞到最后vector里面的数量还是>m 随便挑m个就行*/ 
const int N=200005;
int n,m,ans=-1;
queue<int> q;
void cal(int pe){
	int i=0,memo=q.size();
	for(int i=1;i<=memo;i++){
		int t=q.front();
		q.pop();
		if((t&pe)==1) q.push(t);
	}
//	cout<<"J"<<endl;
	ans=q.front();
	q.pop();
	cout<<q.size()<<endl;
	int memo1=q.size();
	for(int j=1;j<=memo1;j++){
		int t=q.front();
		q.pop();
		ans=(ans&t);
		//cout<<j<<" "<<ans<<endl;
	}
	//cout<<ans<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		q.push(t);
	}
	for(int k=30;k>=0;k--){
		int pe=(1<<k),cnt=0;
		//先计算一下这个位是1的多少个
		for(int i=0;i<q.size();i++){
			int t=q.front();
			q.pop();
			if((pe&t)==pe) cnt++;
			q.push(t);
			//cout<<((pe&t)==pe)<<endl;
			//cout<<"cnt:"<<cnt<<endl;
		}
		if(cnt==m){
			//cout<<"end at"<<k<<endl;
			//cout<<"qsize"<<q.size()<<endl;
			cal(pe);
			break;
		}
		else if(cnt<m){
			//cout<<k<<"con  cnt=="<<cnt<<"(1<<k)=="<<(1<<k)<<endl;
			continue;
		}
		else if(cnt>m){
			int i=0,memo=q.size();
			for(int i=1;i<=memo;i++){
				int t=q.front();
				q.pop();
				if((t&pe)==1) q.push(t);
			}
		}
		//cout<<k<<" left:"<<q.size()<<endl;
	}
	if(ans==-1){
		for(int i=1;i<=m;i++){
			int t=q.front();
			q.pop();
			ans=(ans&t);
		}
	}
	cout<<ans;
	return 0;
}
