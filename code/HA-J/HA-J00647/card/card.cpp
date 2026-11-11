#include<bits/stdc++.h>
using namespace std;
long long n,m,b;
bool B[500005];
int a[500005];
long long ans[500005];
stack<long long> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			b=1;
		}
	}
	if(b==0){
		for(int i=1;i<=m;i++){
			cout<<n<<' ';
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			long long num=a[j];
			if(B[num]==0){
				q.push(num);
				B[num]=1;
			}
			else{
				while(q.top()!=num){
					B[q.top()]=0;
					q.pop();
				} 
			}
		}
		while(!q.empty()){
			int io=q.top();
			ans[io]++;
			B[io]=0;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
