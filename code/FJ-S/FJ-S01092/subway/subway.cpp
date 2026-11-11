#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int k;
int h=1;
vector<string>s2(1e8+5);
vector<vector<int>>r(505,vector<int>(1e4+5));
void bfs (int x,int y,int k,int l){
	string s; 
	 if(k==x){
	 	 s2[h++]=s;
	 	 return;
	 }
	 for(int i=1;i<=n;i++ ){
	 	for(int j=1;j<=k;j++){
	 		if(r[i][j]==k){
	 			s+=k+'0';
	 			bfs(x,y ,r[i][j],k);
	 		}if(r[j][i]==k){
		 		bfs(x,y,k,r[j][i]); 
		 		s+=k+'0';
		 	}
		 }
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	vector<int>v(m+1);
	for(int i=1;i<=m;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int x;
			int t;
			cin>>x>>t;
			r[i][x]=t;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		bfs(x,y,0,y);
		int ans=INT_MAX;
		int sum=0;
		sum=v[x]+v[y];
		for(int i=1;i<=h;i++){
			for(int j=0;j<s2[i].size();j++){
				int g=s2[i][j]-'0';
				sum+=r[s2[i].size()-1-j][g];
			} 
			ans=min(ans,sum);
		}
		cout<<ans;
		cout<<endl;
	}
	return 0;
}
