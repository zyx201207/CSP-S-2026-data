#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5*1e5+5;
int n,m;
int a[N],ans[N];
int vis[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		stack<int>s;
		int cnt=i;
//		cout<<"µÚ"<<i<<"¾Ö"<<endl;
		while(cnt<=n){
			if(vis[a[cnt]]>=1){
				int num=0;
				while(!s.empty()){
					num=s.top();
					s.pop();
//					cout<<"pop->"<<num<<endl;
					if(num==a[cnt])break;
					vis[num]--;
				}
				s.push(a[cnt]);
//				cout<<"push->"<<a[cnt]<<endl;
			}
			else{
				s.push(a[cnt]);
//				cout<<"push->"<<a[cnt]<<endl;
				vis[a[cnt]]++;
			}
			cnt++;
		}
		while(!s.empty()){
			int num=s.top();
			s.pop();
//			cout<<num<<"++"<<endl;
			ans[num]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1

*/
