#include<bits/stdc++.h>
using namespace std;
int c,t,n,y,s;
long long d,x[2000005],sum;
void dfs(int now,int goal,int step){
	if(now==goal){
		if(step==s)y++;
		return;
	}
	if(x[goal]-x[now]<=d)dfs(goal,goal,step+1);
	else for(int i=now+1;x[i]-x[now]<=d;i++)
			dfs(i,goal,step+1);
}
void ds(int now,int goal,int step){
	if(now==goal){
		s=step;
		return;
	}
	int next=now+1;
	if(x[next]-x[now]>d){
		y=0;
		return;
	}
	while(x[next+1]-x[now]<=d)next++;
	ds(next,goal,step+1);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	if(c<=6){
		while(t--){
			cin>>n>>d;sum=0;
			for(int i=1;i<=n;i++)cin>>x[i];
			x[n+1]=LONG_LONG_MAX;
			for(int i=1;i<=n-3;i++)
				for(int j=i+3;j<=n;j++){
					y=0;
					ds(i,j,0);
					if(!s)break;
					dfs(i,j,0);
					if(y==2)sum++;
				}
			cout<<sum<<"\n";
		}
	}else if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>x[i];
			d=d/(x[2]-x[1]);
			if(d<=1){
				cout<<"0\n";
				continue;
			}
			d=2*d-1;
			if(d<n)cout<<n-d<<"\n";
			else cout<<"0\n";
		}
	}else if(c==13||c==14){
		while(t--){
			cin>>n>>d;sum=0;
			for(int i=1;i<=n;i++)cin>>x[i];
			x[n+1]=LONG_LONG_MAX;
			x[0]=LONG_LONG_MIN;
			int sx1,ex1,sy1,ey1,b;
			int sx2,ex2,sy2,ey2;
			for(int i=2;i<n;i++)
				if(x[i]-x[1]<=d&&x[n]-x[i]<=d){
					b=i;break;
				}
			for(sy1=b+1;x[sy1]-x[b-2]<=d;sy1++);
			if(sy1==n+1){
				cout<<"0\n";continue;
			}
			for(ex2=b-1;x[b+2]-x[ex2]<=d;ex2--);
			if(ex2==1){
				cout<<"0\n";continue;
			}
			for(ey1=n;x[ey1]-x[b-1]>d;ey1--);
			for(ex1=b-1;x[b+1]-x[ex1]<=d;ex1--);
			for(sx1=1;x[b]-x[sx1]>d;sx1++);
			for(sy2=b+2;x[sy2]-x[b-1]<=d;sy2++);
			for(ey2=n;x[ey2]-x[b]>d;ey2--);
			for(sx2=1;x[b+1]-x[sx2]>d;sx2++);
			if(sx1<=ex1&&sy1<=ey1)sum=(ex1-sx1+1)*(ey1-sy1+1);
			if(sx2<=ex2&&sy2<=ey2)sum+=(ex2-sx2+1)*(ey2-sy2+1);
			cout<<sum<<"\n";
		}
	}
	return 0;
} 
