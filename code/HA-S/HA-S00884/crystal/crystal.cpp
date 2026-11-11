#include<bits/stdc++.h>
using namespace std;
const int MAXN=10010;
long long n,m;
long long c[MAXN],a[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	long long g=0,d=0;
	for(int i=0;i<n;i++){
		cin>>c[i];
		a[i]=c[i];
	}
	if(n==1){
		cout<<1<<endl;
		return 0;
	}
	if(n==2){
		if(c[0]==c[1]){
			cout<<2<<endl;
			return 0;
		}else{
			if(c[1]-c[0]>=m||c[0]-c[1]>=m){
				cout<<2<<endl;
				return 0;
			}else{
				cout<<1<<endl;
				return 0;
			}
		}
	}
	while(m--){
		sort(c,c+n);
		c[0]++;
	}
	for(int i=0;i<=n;i++){
		if(c[i]==c[i-1]){
			g++;
			d=c[i];
		}
	}
	for(int i=1;i<n;i++){
		if(c[i]-d<m){
			c[i]=d;
			g++;
			if(c[i]<a[i]){
				c[i]=a[i];
				g--;
			}
		}
	}
	cout<<g+1<<"\n";
	return 0;
}
