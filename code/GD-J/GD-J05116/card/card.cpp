#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
	cin>>n>>m;
	vector<int> a(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	vector<int> z(m+1,0);
	for(int i=1;i<=n;i++){
//		cout<<i<<"\n";
		int cnt=0;
		stack<int> s;
		vector<int> p(m+1,0);
		for(int k=i;k<=n;k++){
//			cout<<k<<"\n";
//			cout<<p[a[k]]<<"\n";
			if(p[a[k]]==0){
//				cout<<"stop1\n";
				cnt++;
				p[a[k]]=cnt;
				s.push(a[k]);
			}else{
//				cout<<"stop2\n";
				int l=cnt-p[a[k]];cnt-=l;
				while(l--){
					p[s.top()]=0;s.pop();
				}
//				p[a[k]]=cnt;q.push(a[k]);
			}
//			if(k==6){
//				int l=s.size();
//				while(l--){
//					cout<<s.top()<<"\n";s.pop();
//				}
//				return 0;
//			} 
		}
		while(!s.empty()){
//			if(q.front()==1) cout<<i<<"\n";
			z[s.top()]++;s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<z[i]<<" ";
	}
	return 0;
}
//4 3
//1 2 1 3
//10 3
//3 1 2 1 3 2 3 1 2 1
