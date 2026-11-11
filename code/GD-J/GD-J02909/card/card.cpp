#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
int a[N],ans[N];
bool isins[N];
int main(){
	//¼ì²éfreopenÊÇ·ñ±»×¢ÊÍ 
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		fill(isins+1,isins+1+m,0);
		stack<int>s;
		for(int j=i;j<=n;j++){
			if(!isins[a[j]]){
				s.push(a[j]);
				isins[a[j]]=1;
			}
			else while(s.top()!=a[j]){
				isins[s.top()]=0;
				s.pop();
			} 
		}
		while(!s.empty()){
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
