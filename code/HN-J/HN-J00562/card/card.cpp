#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m;
int a[N];
int ans[M];
int nb[N];
int pos[M];

void solve(int cnt){
	for(int i=cnt;i<=n;i++){
		if(pos[a[i]]==0){
			pos[a[i]]=i;
			nb[i]=a[i];
		}
		else{
			for(int j=pos[a[i]];j<i;j++){
				pos[nb[j]]=0;
				nb[j]=0;
			}
			nb[i]=a[i];
			pos[a[i]]=i;
		}
		
	}
	for(int i=cnt;i<=n;i++){
		ans[nb[i]]++;
		nb[i]=0;
	}
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=1;
	while(cnt<=n){
		solve(cnt);
		cnt++;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
