#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
const int M=3e5+10;
int n,m,a[N],vis[N],ans[M],idx=0;
stack<int> s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				s.push(a[j]);
				vis[a[j]]=++idx;
			}else{
				while(idx>vis[a[j]]){
					vis[s.top()]=0;
					s.pop();
					idx--;
				}
			}	
		}
		while(!s.empty()){
			vis[s.top()]=0;
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout << ans[i] << ' ';
	}
    return 0;
}
