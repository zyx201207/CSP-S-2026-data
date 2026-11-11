#include<bits/stdc++.h>
using namespace std;
const int nm=5e5+5;
int n,m,a[nm],cnt[nm];
bool v[nm];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		stack<int>s;
		for(int j=i;j<=n;j++){
			int d=a[j];
			if(v[d]){
				while(true){
					int f=s.top();
					s.pop();
					v[f]=0;
					if(f==d)break;
				}
			}
			v[d]=1;
			s.push(d);
		}
		for(int j=1;j<=m;j++){
			cnt[j]+=v[j];
			v[j]=0;
		}
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
	return 0;
}
