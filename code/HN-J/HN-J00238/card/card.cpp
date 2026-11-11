#include<bits/stdc++.h>
using namespace std;
/*
1、把每个数字出现位置存在数组
2、遍历出牌 ,每次找到当前牌最后一次位置，（中间直接跳过），对该牌计数，
	再往后找下一张牌，及其最后出现为位置，直到找到最后一张牌 

*/ 
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n , m;
	cin>>n>>m;
	stack<int> st;
	vector<int>  res(m+1 , 0) , a(n+1 , 0);

	for(int i=1 ; i<=n ; i++) cin>>a[i];

	for(int j = 1 ; j <=n ; j++) {
		vector<int> v(m+1 , 0) ;

		for(int i=j ; i <= n; i++) {
			int x = a[i];
			if(v[x] == 0) {
				st.push(x);
				v[x] = 1;
				continue;
			}
			while(!st.empty()) {
				int k = st.top();
//				cout<<"k1 "<<k<<" ";
				if(k==x) break;
				v[k] = 0;
				st.pop();
			}
//			cout<<"\n";
		}
		while(!st.empty()) {
			int k = st.top();
//			cout<<"k:"<<k<<" ";
			res[k]++;
			st.pop();
		}
//		cout<<"---------------\n";
	}

	for(int i= 1; i<= m ; i++) {
		cout<<res[i]<<" ";
	}

	return 0;
}









