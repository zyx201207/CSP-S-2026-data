#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,ans=INT_MIN,Max,wei;
int a[N];
bool vis[N];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
		Max=max(Max,a[i]);
	}
	
	ans=0;
	while(Max!=0){
		wei++;
		Max>>=1; 
	}
	for(int i=wei-1;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&(a[j]&(1<<i))){
				cnt++;
			}
		}
		if(cnt>=m){
			for(int j=1;j<=n;j++){
				if(!vis[j]&&(!(a[j]&(1<<i)))){
					vis[j]=true;
				}
			}
			ans|=(1<<i);
		}
	}
	
	cout<<ans<<endl;
	return 0;
}

