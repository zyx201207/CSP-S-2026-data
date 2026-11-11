#include <cstdio>
#include <cstring>
#include <stack>
#define ll long long
const int N = 5e5 + 5;
const int M = 3e5 + 5;
using namespace std;

int n,m;
int a[N];

int ans[M];
bool f[M];
stack<int> stk;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
	for(int k = n;k;k--){
		while(!stk.empty()) stk.pop();
		for(int i = 1;i <= m;i++) f[i] = false;
		for(int i = k;i <= n;i++){
			if(f[a[i]])
				while(!stk.empty() && stk.top() != a[i]){
					f[stk.top()] = false;
					stk.pop();
				}
			else{
				stk.push(a[i]);
				f[a[i]] = true;
			}
		}
		while(!stk.empty()){
			ans[stk.top()]++;
			stk.pop();
		}
	}
	for(int i = 1;i <= m;i++) printf("%d ",ans[i]);
	return 0;
}

