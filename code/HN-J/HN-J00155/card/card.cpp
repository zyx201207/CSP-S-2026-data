#include<bits/stdc++.h>
using namespace std;
int n,m,ans[333333],b[555555];
stack<int> a;
set<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}for(int i=1;i<=n;i++){
		s.clear();
		while(!a.empty()) a.pop();
		for(int j=i;j<=n;j++){
			int k=b[j];
			if(!s.count(k)){
				s.insert(k);
				a.push(k);
			}else{
				while(a.top()!=k){
					s.erase(a.top());
					a.pop();
				}
			}
		}while(!a.empty()){
			ans[a.top()]++;
			a.pop();
		}
	}for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}

