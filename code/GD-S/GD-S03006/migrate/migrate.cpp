#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=6e5;
int c,t;
int n;
ll d;
ll a[N];
ll sum;
pair<int,int> p[5005][5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n>5000){
			cout<<0<<"\n";
			continue;
		}
		sum=0;
		memset(p,0x3f,sizeof p);
		for(int len=1;len<=n;len++){
			for(int i=1;i+len<=n;i++){
				int j=i+len;
				if(a[j]-a[i]<=d){
					p[i][j]={1,1};
				}
				else{
					for(int k=i+1;k<j;k++){
						int tmp=p[i][k].first+p[k][j].first;
						if(tmp>=0x3f3f3f3f)continue;
//						if(i==1 && j==4)cout<<"k="<<k<<" tmp="<<tmp<<"\n";
						if(p[i][j].first==0x3f3f3f3f || tmp<p[i][j].first){
//							cout<<"1"<<"\n";
							p[i][j]={tmp,1};
						}
						else if(tmp==p[i][j].first){
//							cout<<"2"<<"\n";
							p[i][j]={tmp,p[i][j].second+1};
						}
					}
				}
//				cout<<"i="<<i<<" j="<<j<<" p[i][j]={"<<p[i][j].first<<","<<p[i][j].second<<"}\n";
				if(p[i][j].second==2)sum++;
			}
		}
		cout<<sum<<"\n";
	}
} 
