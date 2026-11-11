#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);cout.tie(NULL);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		vector<int>a(n+5);
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int ans=0;
		for(int start=1;start<=n;start++){
			vector<int>f(n+5,0);
			deque<int>q;
			q.push_back(start);
			for(int i=start+1;i<=n;i++){
				while(!q.empty()&&a[i]-a[q.front()]>d)
					q.pop_front();
//				cout<<"uek,";
				if(q.empty()) break;
				f[i]=f[q.front()]+1;
				if(q.size()>=2){
					int tmp1=q.front();
					q.pop_front();
					int tmp2=q.front();
					q.pop_front();
//					if(start==2&&i==5){
//						cout<<q.size()<<(a[i]-a[q.front()]>d)<<(f[q.front()]!=f[tmp1])<<" ";
//					}
					if(a[i]-a[tmp2]<=d&&f[tmp1]==f[tmp2]&&(q.empty()||a[i]-a[q.front()]>d||f[q.front()]!=f[tmp1]))
						ans++;//cout<<start<<" "<<i<<" ";
					q.push_front(tmp2);
					q.push_front(tmp1);
				}
				while(!q.empty()&&f[i]<f[q.back()])
					q.pop_back();
				q.push_back(i);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
