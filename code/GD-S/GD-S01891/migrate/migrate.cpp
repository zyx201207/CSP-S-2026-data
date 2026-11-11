#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n;
long long a[N],d,cnt,p;
long long check(int x,int y,int s){
	if (s>p) return 0;
	long long ans=0;
	for (int i=x+1;a[i]-a[x]<=d && i<=y;i++){
		if (i==y){
			if (s==p){
				return 1;
			}
			return 0;
		}
		ans+=check(i,y,s+1);
	}
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for (int j=1;j<=t;j++){
		cin>>n>>d;
		for (int i=1;i<=n;i++){
			cin>>a[i];
		}
		cnt=0;
		for (int i=1;i<=n-2;i++){
			for (int k=i+2;k<=n;k++){
				p=0;
				for (int x=i;x<k;){
					int u=x+1;
					while(a[u]-a[x]<=d && u<=k) u++;
					x=u;
					p++;
				}
				if (check(i,k,0)==2) cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
} 
