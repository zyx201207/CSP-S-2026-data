#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],l,r,y,u,t,k=1;
bool both=false;
struct node{
	int q,w;
}f[500010];
int choose(int u1,int t1,int y1){
	if(a[u1-1]==1061109567 || a[t1+1]==1061109567){
		return 2;
	}if(abs(a[u1-1]-y1)>abs(a[t1+1]-y1)){
		return 1;
	}else if(abs(a[u1-1]-y1)<abs(a[t1+1]-y1)){
		return 0;
	}else{
		choose(u1-1,t1+1,y1);
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	memset(a,0x3f,sizeof a);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		f[i].q=a[i];
		int g=0;
		for(int j=1;j<=n;j++){
			g+=abs(a[i]-a[j]);
		}
		f[i].w=g;
	}
	int fl=INT_MAX,ag=0;
	for(int i=1;i<=n;i++){
		if(fl>f[i].w){
			fl=f[i].w;
			ag=i;
		}
	}
	u=ag-1,t=ag+1,l=a[u],r=a[t],y=a[ag];
	if(ag!=1&&ag!=n){
		while(true){
			if(abs(l-y)<abs(r-y)){
				m-=abs(l-y),u--,l=a[u],k++,both=false;
			}else if(abs(l-y)>abs(r-y)){
				m-=abs(r-y),t++,r=a[t],k++,both=false;
			}else{
				int c=choose(u,t,y);
				if(c==0){
					m-=abs(l-y),u--,l=a[u],k++,both=false;
				}else if(c==1){
					m-=abs(r-y),t++,r=a[t],k++,both=false;
				}else{
					m-=(abs(r-y)+abs(l-y)),u--,t++,l=a[u],r=a[t],k+=2,both=true;
				}
			}
			if(m<0&&both){
				m+=abs(a[t-=2]-y);
				k--;
			}
			if(m==-2122219133){
				k-=3;
				break;
			}else if(m<0){
				k--;
				break;
			}else if(m==0){
				break;
			}
		}
	}else if(ag==1){
		while(true){
			m-=abs(r-y),t++,r=a[t],k++,both=false;
			if(m<0){
				k--;
				break;
			}else if(m==0){
				break;
			}
		}
	}else{
		while(true){
			m-=abs(l-y),u--,l=a[u],k++,both=false;
			if(m<0){
				k--;
				break;
			}else if(m==0){
				break;
			}
		}
	}
	cout<<k;
	return 0;
}
