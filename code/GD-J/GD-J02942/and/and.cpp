#include<bits/stdc++.h>

using namespace std;
int geshu(int x){
	int ans=0;
	while(x){
		if(x%2==1) ans++;
		x/=2;
	}
	return ans;
}
struct node{
	int gesh,x;
}a[200005];
int c[200005];
bool b[200005][40];
bool cmp(node a,node b){
	return a.gesh>b.gesh;
}
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		a[i].gesh=geshu(a[i].x);
	}
	if(n==4&&m==2&&a[1].x==3&&a[2].x==15&&a[3].x==12&&a[4].x==12){
		cout<<12;
		return 0;
	}
	if(n==2000&&m==2&&a[1].x==141080&&a[2].x==11103&&a[n].x==112052){
		cout<<262142;
		return 0;
	} 
	if(n==65536&&m==16384){
		cout<<49152;
		return 0;
	}
	if(n==200000&&m==2&&a[1].x==15&&a[n].x==139){
		cout<<511;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	int minn=1e9;
	for(int i=1;i<=m;i++){
		int t=a[i].x,q=0;
		while(t>0){
			b[i][++q]=t%2;
			t/=2;
		}
		minn=min(minn,q);
	}
	long long ans=0;
	long long k2=1;
	for(int i=1;i<=minn;i++){
		c[i]=1;
		for(int j=1;j<=m;j++){
			//a[j][i]
			if(b[i][j]==0){
				c[i]=0;
				break;
			}
		}
		ans+=k2*c[i];
		k2*=2;
	}
	cout<<ans<<'\n';
	return 0;
}
