#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m;
int a[N],t[M];
vector<int> b;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b.clear();
//		for(int j=1;j<=n;j++){
//			b.push_back(a[j]);
//		}
//		cout<<"第"<<i<<"局游戏：\n";
		int idx=-1;
		for(int j=i;j<=n;j++){
			int len=b.size();
			for(int k=0;k<len;k++){
				if(b[k]==a[j]){
					idx=k;
//					cout<<"下标是：";
//					cout<<idx<<"\n";
					break;
				}
			}
			if(idx!=-1){
				b.erase(b.begin()+idx,b.end());
				idx=-1;
//				cout<<"删除了！\n";
			}
			b.push_back(a[j]);
//			cout<<"打出来的牌是："<<a[j]<<"\n";
//			for(auto u:b){
//				cout<<u<<" ";
//			}
//			cout<<"\n";
		}
		for(auto u:b){
//			cout<<u<<" ";
			t[u]++;
		}
//		cout<<"\n";
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}
