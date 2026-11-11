#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,l,r,k1,temp,temp1;
long long t[505][500005],a[500005][20];
long long w[500005],p1[500005];
bool book[500005];
long long dfs(long long k,long long p){
	if(k==r) return t[p][k];
	int g=int(p1[k]-1);
	long long sum=100000000000000000;
	bool flag=1;
	for(long long i=1;i<=g;i++){
		long long ans=0;
	
		if(book[a[k][i]]==0) {
			book[a[k][i]]=1;
			ans=dfs(a[k][i],i);
			book[a[k][i]]=1;
			flag=0;
		}
		if(ans<sum&&ans!=-1) sum=ans;
	}
	if(!flag) return -1;
	else return sum+t[p][k];
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
   cin>>c>>n>>m>>d>>q;
   for(long long i=1;i<=m;i++){
	   cin>>w[i];
   }
   for(long long i=1;i<=n;i++){
	  
	   cin>>k1;
	   for(long long j=1;j<=k1;j++){

		   cin>>temp>>temp1;
		   t[i][temp]=temp1;
		    a[temp][p1[temp]]=i;
		    p1[temp]++;
	   }
   }
   for(long long i=1;i<=n;i++){
	   cin>>l>>r;
	   book[l]=1;
  cout<<w[l]+ dfs(l,0)+w[r]<<"\n";
   book[l]=0;
}
return 0;	
}

