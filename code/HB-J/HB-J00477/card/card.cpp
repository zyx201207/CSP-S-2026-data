#include<bits/stdc++.h>
using namespace std;
stack<int> a;
int card[500001];
int ans[500001],v[500001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>card[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			v[card[j]]++;
			if(v[card[j]]>1){
				while(a.top()!=card[j]&&!a.empty()){
					v[a.top()]=0;
					a.pop();
				}
				a.pop();
			}
			a.push(card[j]);
		}
		while(!a.empty()){
			ans[a.top()]++;
			a.pop();
		}
		memset(v,0,sizeof(v));
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
/*4 3
1 2 1 3*/
