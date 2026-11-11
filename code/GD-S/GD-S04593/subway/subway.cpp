#include<bits/stdc++.h>
using namespace std;
int w[50005],k[505],a[505][50005],t[505][50005];
bool b[50005];
queue<int>ss,tt;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,x,y,mi;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j];
	}while(q--){
		cin>>x>>y;
		for(int i=1;i<=m;i++)b[i]=1; 
		mi=INT_MAX;
		ss.push(x);tt.push(w[x]+w[y]);
		while(!ss.empty()&&!tt.empty()){
			for(int i=1;i<=n;i++){
			    for(int j=1;j<=k[i];j++){
			   		if(b[i]&&a[i][j]==ss.front()){
			    		for(int l=1;l<=k[i];l++){
			    			b[j]=0;
				    		tt.push(t[i][j]+t[i][l]+tt.front());
			    			ss.push(a[i][l]);
			    			if(a[i][l]==y) mi=min(t[i][j]+t[i][l]+tt.front(),mi);
			    		}
			    	}
				}
			}ss.pop();tt.pop();
		}cout<<mi<<endl;
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}
