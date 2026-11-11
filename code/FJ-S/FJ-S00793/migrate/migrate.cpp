#include<bits/stdc++.h>
using namespace std;
int c,ti;
int n,d;
int x[2000005];
vector<int>v[100005],r[100005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>ti;
	while(ti--){
		cin>>n>>d;
		if(n>20000){
			cout<<0;
			return 0;
		}
		for(int i=1;i<=n;i++)v[i].clear();
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=2;i<=n;i++)x[i]-=x[1];
		x[1]=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					v[i].push_back(j);
					r[j].push_back(i);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(v[i].size()!=2)continue;
			bool t=0;
			int s=i,e=0;
			for(int j=i+2;j<=n;j++){
				if(v[j].size()>1){
					break;
				}
				if(r[j].size()==2){
					t=1;
					e=j;
					break;
				}
			}
			int p1=s,p2=e;
			int q1=1,q2=1;
			while(r[p1].size()==1){
				p1--;
				q1++;
			}
			while(v[p2].size()==1){
				p2++;
				q2++;
			}
			ans+=q1*q2;
		}
		cout<<ans<<"\n";
	}
}
