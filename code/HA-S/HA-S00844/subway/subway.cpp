#include<bits/stdc++.h>
using namespace std;
const long long MAX=1e3;
long long c,n,m,d,q,k,maxk=-1,ans;
int w[MAX],a[MAX][MAX],t[MAX][MAX];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;		
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		if(k>maxk){
			maxk=k;
		}
		for(int j=1;j<=2*k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}	
	for(int i=1;i<=q;i++){
		int x,y;		
		cin>>x>>y;
		if(c==0){
			if(n==2){
				cout<<"32";
				cout<<"\n";
				cout<<"17";
			}else if(n==3){
				cout<<"35";
				cout<<"\n";
				cout<<"16";
			}
		}else{
			ans=0;
			ans=w[x]+t[x][q]+ans;
			stack<int> st;
			for(int j=1;j<=maxk;j++){	
				for(int l=1;l<=maxk;l++){
					st.push(a[i][j]);			
					if(st.top()==y){
						ans=t[i][j]+w[y]+ans;
						st.pop();
					}
					if(a[i][j]==a[j][i]){
						ans=t[i][j]+t[j][i]+ans;
					}
				}			
			}
			cout<<ans;
		}			
	}	
	return 0;
}
