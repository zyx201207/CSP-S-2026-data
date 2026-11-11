#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+1;
long long a[N][31],n,x,t=30,m,maxx=100,sum,ans,p;
bool f[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>x;
		t=30;
		while(x){
			a[i][t]=x%2;
			t--;
			x/=2;
		}
		maxx=min(maxx,t);
	}
	p=pow(2,30-maxx);
	for(int j=maxx;j<31;j++){
		sum=0;
		for(int i=0;i<n;i++){
			if(a[i][j]==1 && !f[i]) sum++;
		}
		if(sum>=m){
			ans+=p;
			for(int i=0;i<n;i++){
				if(a[i][j]==0) f[i]=1;
			}
		} 
		p/=2;
	}
	cout<<ans;
	return 0;
} 
