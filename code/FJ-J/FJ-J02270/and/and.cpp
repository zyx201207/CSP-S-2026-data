#include<bits/stdc++.h> 
using namespace std;
#define endl '\n'
const int N=2e5+10;
int n,m,a[N],mx,ans;
bool st[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=1;
		while((1<<x)<a[i])x++;
		mx=max(x,mx);
		st[i]=1;
	}
	int t=mx;
	while(t--){
		int pos=0;
		queue<int>q;
		for(int i=1;i<=n;i++){
			if(((1<<t)&a[i])&&st[i]){
				pos++;	
			}else{
				q.push(i);
			}
		}
		if(pos>=m){
			while(q.size()){
				int tf=q.front();q.pop();
				st[tf]=0;
			}
			ans+=(1<<t);
		}
	}
	cout<<ans;
	return 0;
}
	
