#include<bits/stdc++.h>
using namespace std;
vector<int>s[2000006];
long long a,b,c,d[2000006],t,mi,su;
int bfs(int u,int v,int p){
	if(u==v&&p==mi){
		su++;
		return 0;
	}
	if(p>=mi){
		return 0;
	}
	for(int i=0;i<s[u].size()&&s[u][i]<=v;i++){
		bfs(s[u][i],v,p+1);
	}
	
	return su;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n=0;
		cin>>a>>b;
		for(int i=1;i<=a;i++){
			cin>>d[i];
			s[i].clear();
		}
		for(int i=1;i<=a;i++){
			for(int j=i+1;j<=a&&d[j]-d[i]<=b;j++){
				s[i].push_back(j);
			}
		}
		for(int i=1;i<=a;i++){
			for(int j=i+1;j<=a;j++){
				if(d[j]-d[i]>b&&s[i].size()!=0){
					 mi=1;
					for(int k=s[i][s[i].size()-1];mi!=-1&&k<j;mi++){
						if(s[k].empty()==1){
							mi=-1;
							break;
							
						}
						k=s[k][s[k].size()-1];
						
					}
					
					su=0;
					if(bfs(i,j,0)==2){
						n++;
					}
				}
			}
		}
		cout<<n<<endl; 
	}
} 
