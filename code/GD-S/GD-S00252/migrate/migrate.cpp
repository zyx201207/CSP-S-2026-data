#include<bits/stdc++.h>
using namespace std;
int t,c,n,d;
long long x[5005];
int cnt[15][15],mi[15][15];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","r",stdout);
	cin>>c>>t;
	while(t--){
     cin>>n>>d;
     int ans=0;
      for(int i=1;i<=n;i++)cin>>x[i];
      for(int i=0;i<(1<<n);i++){
      	 vector<int> v;
      	 for(int j=0;j<n;j++){
      	 	if(i&(1<<j)){
                v.push_back(j+1);	 		
			}
		 }
		 if(v.size()<2)continue;
		 bool f=0;
		 for(int i=1;i<v.size();i++){
		 	if(x[v[i]]-x[v[i-1]]>d){
		 		f=1;
		 		break;
			 }
		 }
		 if(!f){
		 	if(mi[v[0]][v[v.size()-1]]==0||mi[v[0]][v[v.size()-1]]>v.size()){
		 		cnt[v[0]][v[v.size()-1]]=1;
		 		mi[v[0]][v[v.size()-1]]=v.size();
			}else if(mi[v[0]][v[v.size()-1]]==v.size())cnt[v[0]][v[v.size()-1]]++;
	    }
	  }
	  for(int i=1;i<=n;i++)
	   for(int j=i+1;j<=n;j++)
	    if(cnt[i][j]==2)
		  ans++;
	   cout<<ans<<"\n";
   }
}





