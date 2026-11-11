#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d,tot=0;
		cin>>n>>d;
		if(n>=20){
			if(d<=1)	cout<<"0\n";
			else cout<<n+1-2*d<<'\n'; 
			continue;
		}
		for(int i=1;i<=n;i++)	cin>>a[i];
		for(int l=1;l<=n;l++){
			for(int r=l+3;r<=n;r++){
				int len=r-l-1;
				int minn=INT_MAX,cnt=0;
				for(int mar=0;mar<(1<<len);mar++){
					vector<int> dis;
					dis.push_back(a[l]);
					for(int i=0;i<len;i++){
						if(mar&(1<<i))	dis.push_back(a[l+i+1]);
					}
					dis.push_back(a[r]);
//					printf("(%d,%d)",l,r);
//					for(auto x:dis){
//						cout<<x<<" ";
//					}
					bool av=1;
					for(int i=1;i<dis.size();i++){
						if(dis[i]-dis[i-1]>d){
//							printf("can't on %d %d",dis[i],dis[i-1]);
							av=0;
							break;
						}
					}
					if(av==0)	continue;
					if(dis.size()==minn){
						cnt++;
					}
					if(dis.size()<minn){
						cnt=1;
						minn=dis.size();
					}
					
				}
				if(cnt==2)	/*printf("(%d,%d)",l,r),*/tot++;
			}
		}
		cout<<tot<<'\n';
	}
}
