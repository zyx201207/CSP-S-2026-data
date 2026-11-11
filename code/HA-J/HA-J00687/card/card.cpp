#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],l,r,k,maxx,cnt[200005],ans[200005];
bool b[200005];
stack<int> s;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int x=1;x<=n;x++){
		for(int i=x;i<=n;i++){
			if(cnt[a[i]]){
				while(s.top()!=a[i]&&s.size()){
					int num=s.top();
					s.pop();
					cnt[num]--;
				}
				int num=s.top();
				s.pop();
				cnt[num]--;
			}
			cnt[a[i]]++;
			s.push(a[i]);
		}
		while(s.size()){
			s.pop();
		}
		for(int i=1;i<=m;i++){
			if(cnt[i]){
				cnt[i]=0;
				ans[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
		if(i!=m){
			cout<<' ';
		}
	} 
	return 0;
}
