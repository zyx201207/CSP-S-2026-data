#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],f[300005],sum[300005];
stack<int>q;
//stack<int>q1;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[a[i]]=-1;
	}
	for(int k=1;k<=n;k++){
		while(!q.empty())q.pop();
		for(int i=k;i<=n;i++){
			if(f[a[i]]!=-1){
				while(f[a[i]]<q.size()){
					f[q.top()]=-1;
					q.pop();
				}
			}
			f[a[i]]=q.size();
			//cout<<a[i]<<" "<<f[a[2]]<<"   ";
			q.push(a[i]);
//			while(!q.empty()){
//				cout<<q.top()<<" ";
//				q1.push(q.top());
//				q.pop();
//			}
//			while(!q1.empty()){
//				q.push(q1.top());
//				q1.pop();
//			}
//			cout<<endl;
		}
		//cout<<endl;
		for(int i=1;i<=m;i++){
			if(f[i]!=-1)sum[i]++;
			f[i]=-1;
		}
	}
	for(int i=1;i<=m;i++)cout<<sum[i]<<" ";
}
