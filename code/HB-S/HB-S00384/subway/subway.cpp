#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x[100005],y[100005],sum,l[505];
long long w[505];
vector<long long> a[1000005],t[1000005];
int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int b;
		cin>>b;
		for(int j=1;j<=b;j++){
			int u,v;
			cin>>u>>v;
			a[i].push_back(u);
			t[i].push_back(v);
		}
	}
	for(int i=1;i<=q;i++){
		 cin>>x[i]>>y[i];
 	}
	for(int i=1;i<=q;i++){
		sum=w[x[i]];
		 int z=x[i];
		 int tt;
		 for(int i=1;i<=n;i++){
			if((a[i][0]==z)||(a[i][1]=z)){
				tt=i;
				break;
			}
		 }
		 while(z!=y[i]){
			 for(int i=1;i<=n;i++){
	    		 if(((a[i][0]==z)||(a[i][1]==z))&&i!=tt){
	    			 tt=i;
	     			 break;
		    	}
		     }
		     int h;
		     int ll=a[tt].size()-1;
		     int j;
     	     for(j=0;j<=ll;j++){
				 int min1=1e9;
				 
    		      if(a[tt][j]!=z){
					  if(min1>t[tt][j]){
						  min1=t[tt][j];
						  z=a[tt][j];
						  h=j;
					  }
				  }
    		 }
    		 sum+=t[tt][h];
    		 sum+=t[tt][h];
		 }
		 sum+=w[y[i]];
		 if(i==q){
			 cout<<sum;
		 }
		 else{
			 cout<<sum<<endl;
		 }
	}
	return 0;
}
