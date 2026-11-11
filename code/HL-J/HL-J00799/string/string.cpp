#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using ll =unsigned long long;
struct node {
	int a;char c;
};
deque<node> q;
ll ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin >> n;
	for (int i=1;i<=n;i++){
		node ci;
		cin >> ci.a >> ci.c;
		q.push_back(ci);
	}	
	while (q.size()>1){
		node x=q.front(),y=q.back();q.pop_front();q.pop_back();
		if (x.a==y.a){
			if (x.c!=y.c)ans+=x.a;
		}else{
			if (x.c==y.c){
				node z;
				z.a=abs(x.a-y.a);z.c=x.c;
				q.push_back(z);
			}else{
				node z;
				z.a=abs(x.a-y.a);
				ans+=abs(x.a-y.a);
				if (x.a>y.a){
					z.c=x.c;
				}else{
					z.c=y.c;
				}
				q.push_back(z);
			}
		}
	}
	cout << ans;
}
	      
