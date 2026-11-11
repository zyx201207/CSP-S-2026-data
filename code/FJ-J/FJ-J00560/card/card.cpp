#include<bits/stdc++.h>
#include<stack>
using namespace std;

int n,m;
int x[500005],sum[300005];
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
//	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		stack<int> a;
		int b[300005]={0};
		for(int j=i;j<=n;j++){
			a.push(x[j]);
			b[x[j]]++;
			if(b[x[j]]>1){
				a.pop();
				b[x[j]]--;
				while(a.top()!=x[j]){
					b[a.top()]--;
					a.pop();
				}
			}
		}
		while(!a.empty()){
//			cout<<a.top()<<" ";
			sum[a.top()]++;
			a.pop();
		}
//		cout<<"\n";
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
