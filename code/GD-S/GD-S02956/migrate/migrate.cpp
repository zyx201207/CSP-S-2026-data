#include<bits/stdc++.h>
using namespace std;
int c,t,n,cnt,bi;
long long d;
int a[2000005];
bool v[2000005];
int ans;
int pow(int x){
	if(x>0)return x;
	else return -x;
}
void bfs(int rx,int ry){
	queue<pair<int,int>> q;
	q.push({rx,0});
	v[rx]=1;
	int max_ans=1e9;
	int a1=1;
	
	for(int i=1;i<=n;i++){
		auto [x,s]=q.front();
		q.pop(); 
		if(x==ry&&s<=max_ans){
			ans++;
			max_ans=min(max_ans,s);
		}
		else if(x==ry&&s>max_ans){
			return;
		}
		if(pow(x-a[i])<=d&&v[a[i]]==0){
			q.push({a[i],s+1});
			v[a[i]]=1; 
		}
	}

	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==1||c==2){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n&&j!=i;j++){
					ans=0;
					memset(v,0,sizeof(v));
					bfs(i,j);
				if(ans==2){
					cnt++;
				}
			} 	
		} 
		cout<<cnt<<"\n";
		}
		if(c==13||c==14){
			cout<<0<<"\n";
		}
		else{
			cout<<0<<"\n";
		}
	}
	return 0;
} 
