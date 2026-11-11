#include<bits/stdc++.h>
using namespace std;
int a[200009],ans;
bool b[39][200009],book[200009];
void ch(int u){
	int cnt=0,k=a[u];
	while(k){
		if(k&1){
			b[cnt][u]=1;
		}
		k>>=1;
		cnt++;
	}
}
bool cmp(int p,int q){return p>q;}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,i,j,cnt;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i],book[i]=1;
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i++) ch(i);
	for(i=31;i>=0;i--){
		cnt=0;
		for(j=1;j<=n;j++){
			if(book[j]){
				if(b[i][j]) cnt++;
			}
		}
		if(cnt>=m){
			ans+=(1<<i);
			for(j=1;j<=n;j++){
				if(!b[i][j]) book[j]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}