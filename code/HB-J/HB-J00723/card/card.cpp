#include<bits/stdc++.h>
using namespace std;
int a[500010],f[300010],s[300010];
int n,m;
stack<int>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>0;i--){
		int x=a[i];
		if(f[x]){
			for(;;){
				if(q.top()==x){
					q.pop();
					break;
				}else{
					s[q.top()]+=f[q.top()]-i;
					f[q.top()]=0;
					q.pop();
				}
			}
			q.push(x);
		}
		else{
			f[x]=i;
			q.push(x);
		}
	}
	for(;!q.empty();){
		s[q.top()]+=f[q.top()];
		q.pop();
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<' ';
	}
	
	return 0;
}
