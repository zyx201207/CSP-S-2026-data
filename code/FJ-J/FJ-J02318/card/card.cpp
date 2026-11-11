#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
//const int N=1e5+10;
struct node{
	int f,p;
}s[3010];
int n,m,a[200010],b[200010],x[3010];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k=1;
		for(int j=i;j<=n;j++){
			if(s[a[j]].f==1){
				for(int l=s[a[i]].p+1;l<k;l++){
					s[b[l]].f=0;
				}
				k=s[a[i]].p+1;
			}else{
				b[k]=a[j];
				s[a[j]].f=1,s[a[j]].p=k;
				k++;
			}
		}
		for(int j=1;j<k;j++) cout<<b[j]<<" ";
		cout<<endl;
		for(int j=1;j<k;j++) x[b[j]]++;
		for(int j=1;j<=n;j++){
			b[j]=0;
		} 
		for(int j=1;j<=m;j++){
			s[j].f=0,s[j].p=0;
		}
	}
	x[a[n]]=n;
	for(int i=1;i<=m;i++){
		cout<<x[i]<<" ";
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	solve();
	return 0;
}
