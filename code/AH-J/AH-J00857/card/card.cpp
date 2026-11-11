#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
typedef long long ll;
ll n,m,a[500010],cnt[500010];
stack<ll> s;
bool f[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		while(!s.empty()) s.pop();
		memset(f,0,sizeof(f));
		for(ll j=i;j<=n;j++){
			if(f[a[j]]==0){
				s.push(a[j]);
				f[a[j]]=1;
			}else{
				while(!s.empty()){
					if(s.top()==a[j]) break;
					f[s.top()]=0;
					s.pop();
				}
			}
		}
		while(!s.empty()){
			cnt[s.top()]++;
			s.pop();
		}
	}
	for(ll i=1;i<=m;i++) cout<<cnt[i]<<" ";
    return 0;
}
