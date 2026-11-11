#include<bits/stdc++.h>
using namespace std;
int n,m,d=0;
int a[200005];
int bfs(int ans,int cnt){
	if(cnt<m){
		for(int i=0;i<n;i++){
			if(ans==-1){
				d=max(d,bfs(a[i],cnt+1));
			}
			else{
				int x[30]={},y[30]={},xi=0,yi=0,xx=ans,yy=a[i],xy=0;
				while(xx){
					x[xi]=xx%2;
					xx/=2;
					xi++;
				}
				while(yy){
					y[yi]=yy%2;
					yy/=2;
					yi++;
				}
				for(int i=0;i<min(xi,yi);i++){
					if(x[i]==y[i]){
						int s=1;
						for(int j=0;j<i;j++){
							s*=2;
						}
						xy+=s;
					}
				}
				d=max(d,bfs(xy,cnt+1));
			}
			if(cnt>=m){
				break;
			}
		}
	}
	return d;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		int maxi=0;
		for(int i=0;i<n;i++){
			if(a[i]>maxi){
				maxi=a[i];
			}
			cout<<maxi<<'\n';
			return 0;
		}
	}
	if(m==n){
		int ans=-1;
		for(int c=0;c<n;c++){
			int x[30]={},y[30]={},xi=0,yi=0,xx=ans,yy=a[c],xy=0;
			if(ans==-1){
				ans=a[c];
				break;
			}
			while(xx){
				x[xi]=xx%2;
				xx/=2;
				xi++;
			}
			while(yy){
				y[yi]=yy%2;
				yy/=2;
				yi++;
				}
			for(int i=0;i<min(xi,yi);i++){
				if(x[i]==y[i]){
					int s=1;
					for(int j=0;j<i;j++){
						s*=2;
					}
					xy+=s;
				}
			}
			ans=xy;
		}
		cout<<ans<<'\n';
		return 0;
	}
	cout<<bfs(-1,0)<<'\n';
	return 0;
}
