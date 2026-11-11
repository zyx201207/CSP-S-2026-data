#include<bits/stdc++.h>
using namespace std;
int n;
long long d,x[2000005];
long long bfs(int s){
	queue<int> q;
	q.push(s);
	vector<int> amin(2000005,2147483647);
	vector<int> anum(2000005,0);
	amin[s]=0;
	anum[s]=1;
	long long now,ans=0;
	while(!q.empty()){
		now=q.front();
		q.pop();
		for(int i=now+1;i<n;i++){
			if(x[i]-x[now]>d){
				break;
			}if(amin[i]>amin[now]+1){
				q.push(i);
				amin[i]=amin[now]+1;
				anum[i]=1;
			}else if(amin[i]==amin[now]+1){
				q.push(i);
				anum[i]++;
			}
		}
	}for(int i=s;i<n;i++){
		if(anum[i]==2){
			ans++;
		}
	}return ans;
}
int f(){
	cin>>n>>d;
	if(n<=3){
		for(int i=0;i<n;i++){
			cin>>d;
		}return 0;
	}for(int i=0;i<n;i++){
		cin>>x[i];
	}int m=0;
	for(int i=0;i<n-3;i++){
		m+=bfs(i);
	}return m;
}int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.out","w",stdout);
	freopen("migrate.in","r",stdin);
	int t;
	cin>>t>>t;
	for(int i=0;i<t;i++){
		cout<<f()<<endl;
	}
	return 0;
}
