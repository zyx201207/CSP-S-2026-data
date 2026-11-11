#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5,M=5e5+5;
int ans[N],a[M],n,m;
unordered_map<int,int> mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]=1;
		ans[a[i]]=i;
	}
//	for(int i=1;i<=n;i++){
//		deque<int> q;
//		mp.clear();
//		for(int id=i;id<=n;id++){
//			if(mp[a[id]]==0){
//				q.push_back(a[id]);
//				mp[a[id]]=1;
//			}
//			else{
//				int cnt=0,size=q.size();
//				for(int j=1;j<=size;j++){
//					if(q.front()!=a[id]){
//						q.push_back(q.front());
//						q.pop_front();
//					}
//					else{
//						for(int k=1;k<=size-cnt;k++){
//							mp[q.front()]=0;
//							cout<<q.front()<<" ";
//							q.pop_front();
//						}
//						cout<<"\n";
//						q.push_back(a[id]);
//						mp[a[id]]++;
//					}
//				}
//			} 
//		}
////		for(int k=1;k<=q.size();k++){
////			cout<<q.front()<<" ";
////			ans[q.front()]++;
////			q.pop_back();
////		} 
////		cout<<"#"<<i<<"\n";
//	}
	for(int i=1;i<=m;i++){
		cout<<(mp[i]==1?ans[i]:0)<<" ";
	}
	return 0;
} 
/*
4 2 
1 2 1 3
*/
