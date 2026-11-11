#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
int n,m,a[500010],ans[300010];
bool b[300010];
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				s.push(a[j]);
				b[a[j]]=1;
			}
			else{
				while(s.top()!=a[j]){
					b[s.top()]=0;
					s.pop();
				}
			}
		}
		while(!s.empty()){
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
