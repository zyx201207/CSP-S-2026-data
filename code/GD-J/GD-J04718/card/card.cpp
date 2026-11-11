#include<bits/stdc++.h>
#define int ll
#define inf 0x3f3f3f3f3f3f3f3fll
#define endl '\n'
typedef long long ll;
using namespace std;
const int N=1000010;

int n,m;
int a[N],ans[N];
bool in[N];
stack<int>s;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int _=1;_<=n;_++){
		memset(in,0,sizeof(in));
		while(!s.empty())s.pop();
		
		for(int i=_;i<=n;i++){
			if(in[a[i]]){
				while(s.top()!=a[i]){
					in[s.top()]=0;
					s.pop();
				}
			}
			else{
				s.push(a[i]);
				in[a[i]]=1;
			}
		}
		for(int i=1;i<=m;i++){
			ans[i]+=in[i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
    return 0;
}

