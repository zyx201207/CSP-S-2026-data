#include <bits/stdc++.h>
using namespace std;

struct stu{
	int x,t;
};

const int M = 3e5+10;
long long n,m,a[M],ans[M];
bool vis[M],f=0;
stack <stu> st;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		int x;
		cin >> x;
		if(!vis[x]){
			vis[x]=1;
			st.push({x,i});
		}else{
			int cnt,ti;
			while(cnt!=x){
				cnt=st.top().x,ti=st.top().t;
				vis[cnt]=0;
				ans[cnt]+=i-ti;
				st.pop();
			}
			st.push({x,i});
			vis[x]=1;
		}
		cout << st.top().x << " ";
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}
