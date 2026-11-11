#include<bits/stdc++.h>
using namespace std;
const int MAXN2=3*1e5+50;
queue<int>a;
queue<int>zhuo;
bool is[MAXN2];
int ans[MAXN2];
int t;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios_base::sync_with_stdio(NULL);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>t;
		a.push(t);
	}
	for(int i=0;i<n;i++){
		int s=a.size();
		for(int j=i-1;j<=s;j++){
			for(int k=0;k<=j-1;k++){
				a.push(a.front());
				a.pop(); 
			}
			if(!is[a.front()]){
				is[a.front()]=1;
				zhuo.push(a.front());
				a.pop();	
			}
			else{
				while(zhuo.size()) zhuo.pop();
			}
			for(int k=0;k<j;k++){
				a.push(a.front());
				a.pop(); 
			}
			for(int i=1;i<=m;i++){
				if(is[i]){
					a.push(i);
					ans[i]++;
					is[i]=0;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(ans[i]) cout<<ans[i]<<" ";
	}
	return 0;
}
