#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[300010];
bool b[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	stack<int>p;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			b[j]=0;
		}
		
		for(int j=i;j<=n;j++){
			//for(int k=1;k<=m;k++){
			//	if(b[k]) cout<<k<<'p';
			//}
			//cout<<' ';
			if(b[a[j]]==1){
				//cout<<"qqq";
				while(p.size() && p.top()!=a[j]){
					b[p.top()]=0;
					p.pop();
				}
				continue;
			}
			else{
				p.push(a[j]);
				//cout<<a[j]<<' ';
				b[a[j]]=1;
			}
		}
		//cout<<'\n';
		while(p.size()){
			//cout<<p.top()<<' ';
			ans[p.top()]++;
			p.pop();
		}
		//cout<<'\n';
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}

	return 0;
}

