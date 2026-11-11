#include<bits/stdc++.h>
using namespace std;
stack<int> s;
int ans[300005],a[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		bool b[300005]={false};
		for(int j=i;j<=n;j++){
			s.push(a[j]);
			if(b[a[j]]){
				s.pop();
				while(true){
					if(s.top()==a[j]){
						break;
					}
					else{
						b[s.top()]=false;
						s.pop();
					}
				}
			}
			else{
				b[a[j]]=true;
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
}
