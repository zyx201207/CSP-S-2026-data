#include<iostream>
#include<stack>
using namespace std;
int n,m;
int a[500005];
long long d[500005];
long long num[300005];
int fir[300005];
bool vis[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
//	freopen("card4.in","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5000){
		stack<int> q;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(vis[a[j]]){
					while(!q.empty()&&q.top()!=a[j]){
						vis[q.top()]=0;
						q.pop();
					}
					continue;
				}
				vis[a[j]]=1;
				q.push(a[j]);
			}
			while(!q.empty()){
//				cout<<q.top()<<" ";
				vis[q.top()]=0;
				num[q.top()]++;
				q.pop();
			}
//			cout<<endl;
		}
		for(int i=1;i<=m;i++){
			cout<<num[i]<<" ";
		}
		return 0;
	}
	for(int i=n;i>=1;i--){
		d[i]++;
		if(fir[a[i]]){
			d[i]-=1;
			d[fir[a[i]]]+=1;
			continue;
		}
		fir[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		d[i]=d[i-1]+d[i];
		if(d[i]>=0) num[a[i]]+=d[i];
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<" ";
	}
	return 0;
}
//50?
