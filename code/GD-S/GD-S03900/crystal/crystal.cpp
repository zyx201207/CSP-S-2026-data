#include<bits/stdc++.h>
using namespace std;
int a[500050];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//每次选定一个数，将他与其他数的差入队，看m能打败几个
	long long maxn=INT_MIN;
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		priority_queue<int,vector<int>,greater<int>>q;
		for(int j=1;j<i;j++){
			int p=a[i]-a[j];
			q.push(p);
		}
		long long ans=1,k=m;
		while(!q.empty()){
			//cout<<q.top()<<" ";
			if(q.top()<=k){
				ans++;
				k-=q.top();
				q.pop();
			}else break;
			
		}
		maxn=max(maxn,ans);
	}
	cout<<maxn;
}
