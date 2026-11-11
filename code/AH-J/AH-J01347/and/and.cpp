#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
bool f[200005][32];
bool b[200005];
queue<int> q;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=a[i],j=0;
		while(x){
			if(x%2)f[i][j]=1;
			j++,x/=2;
		}
	}
	int s;
	for(int i=29;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(f[j][i]){
				q.push(j);
				cnt++;
			}
		}
		if(cnt>=m){
			while(!q.empty()){
				int t=q.front();
				b[t]=1;
				q.pop();
			}
			ans+=1<<i;
			s=i-1;
			break;
		}
		while(!q.empty())q.pop();
	}
	for(int i=s;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(f[j][i]&&b[j]){
				cnt++;
			}
			else if(b[j]==1){
				q.push(j);
			}
		}
		if(cnt>=m){
			while(!q.empty()){
				int t=q.front();q.pop();
				b[t]=0;
			}
			ans+=1<<i;
		}
		while(!q.empty())q.pop();
	}
	cout<<ans;
	return 0;
}

