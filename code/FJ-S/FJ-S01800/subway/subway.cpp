#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,p;
long long w[500002];
long long number[502];
long long a[502][22];//1 2 4         2 3 5
long long t[502][22];
long long r[2][100002];
int ans=0;
long long tt[500002];
void printt(int mm,int nn){
	memset(tt,0,sizeof(tt));
	int ans=w[mm]+w[nn];
	queue<int> q;int x=ans;
	q.push(mm);
	tt[mm]==1;
	while(!q.empty()){
		
		for(int i=1;i<=n;i++){
		    for(int j=1;j<=number[i];j++){
			    if(a[i][j]==q.top()){
			    	x+=t[i][j];
			    	if(tt[a[i][j+1]]==0){
			    		tt[a[i][j+1]]=1;
					    push(a[i][j+1]);
					}
			    	if(a[i][j-1]==0){
			    		tt[a[i][j+1]]=1
			    		push(a[i][j-1]);
					}
				}
				if(q.top==nn){
					ans=min(ans,x);
				}
		    }
	    }
		
	}
	cout<<ans;
}
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
	    cin>>number[i];
	    for(int j=1;j<=number[i];j++){
	    	cin>>a[i][j]>>t[i][j];
		}
	}
	for(long long i=1;i<=q;i++){
		cin>>r[1][i]>>r[2][i];
		printt(r[1][i],r[2][i]);
	}
	
	return 0;
}