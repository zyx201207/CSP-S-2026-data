#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[505][5005],e[505][505],l[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,x,y;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>l[i];
		for(int j=0;j<l[i];j++){
			cin>>b[i][j]>>e[i][j];
		}
	}

	for(int z=0;z<q;z++){
		int v=1,w=1,r,t,p;
		cin>>x>>y;
		c=a[x-1]+a[y-1];
		for(int i=0;i<n;i++){
			for(int j=0;j<l[i];j++){
				if(b[i][j]==x&&v){
					c+=e[i][j];
					r=i;
					v=0;
				}
				if(b[i][j]==y&&w){
					c+=e[i][j];
					t=i;
					w=0;
				}
			}
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(b[0][i]==b[1][j]){
						p=e[0][i]+e[1][j];
					}
				}
			}
			if(r!=t){
				c+=p/2; 
			}
		}
		cout<<c<<endl;
	}
	

	return 0;
}
