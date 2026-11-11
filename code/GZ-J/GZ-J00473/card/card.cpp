//GZ-J00473 遵义市第四初级中学 陈昊然
#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long cs[300005];
int main() {
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0; i<=n-1; i++) {
		cin>>a[i];
	}
	long long n_1=n;
	for(int i=0; i<=n-1; i++) {
		set<long long> que;
		for(int j=i; j<=n-1; j++) {
			if(que.find(a[j])!=que.end()) {
				set<long long>::iterator it2;
				for(it2=que.begin(); it2!=que.end(); it2++) {
					que.erase(*it2);
				}
			}
			que.insert(a[j]);
		}
		set<long long>::iterator it;
		for(it=que.begin(); it!=que.end(); it++) {
			cs[*it]++;
		}
	}
	for(int i=1; i<=m; i++) {
		cout<<cs[i]<<" ";
	}
	return 0;
}

