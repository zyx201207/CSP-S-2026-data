#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N=1e6+5;
const int mod=1e9+7;
const int inf=2e9;

int n,m;
int a[N];
int v[N];
int ans[N];
 
void solve(int s){
	stack <int> z;
	for(int i=s;i<=n;i++){
		int ls=a[i];
		if(v[ls]>0){
			while(z.size() && z.top()!=ls){
				v[z.top()]--;
				z.pop();
			}
			z.pop();
			v[ls]--;
		}
		v[ls]++;
		z.push(ls);
	}
	while(z.size()){
		ans[z.top()]++;
		v[z.top()]--;
		z.pop();
	}
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		solve(i);
	}
	for(int i=1;i<=m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}


