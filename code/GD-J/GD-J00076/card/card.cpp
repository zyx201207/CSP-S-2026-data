#include<bits/stdc++.h>
#define N 500005
#define M 300005
#define ll long long
using namespace std;
int n,m,xt;
ll a[N],dc[M]; 
void mn(int k){
	int v[N];
	memset(v,0,sizeof v);
	for(int i=k;i<=n;i++){
		if(v[a[i]]){
			for(int j=i-1;j>=k;j--){
				if(a[j]==a[i]) break;
				v[a[j]]=0;
			}
		}
		else v[a[i]]=1;
	}
	for(int i=1;i<=m;i++){
		if(v[i]) dc[i]++;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) mn(i);
	for(int i=1;i<=m;i++){
		cout<<dc[i]<<" ";
	}
	return 0;
} 
