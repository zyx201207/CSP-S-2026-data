#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q,a,ta,b,x,y,now1,w[500001],qin[100001][2];
int begli=0,endli=-1,li[500001];

void push(int px){
	endli=(endli+1)%500000;
	li[endli]=px;
}

int pop(){
	int temp1=li[begli];
	begli=(begli+1)%500000;
	return temp1;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	int time1[n+m+1][n+m+1],ans[m][n+m+1],tong[m];
	for(int i=0;i<n+m+1;i++){
		for(int j=0;j<n+m+1;j++){
			time1[i][j]=-1;
		}
	}
	for(int i=0;i<n;i++){
		cin>>b;
		for(int j=0;j<b;j++){
			cin>>a>>ta;
			a--;
			time1[a][i+m]=ta;
			time1[i+m][a]=ta;
		}
	}
	memset(tong,0,sizeof(tong));
	for(int i=0;i<q;i++){
		cin>>x>>y;
		if(tong[y-1]==0){
			qin[i][0]=x-1;
			qin[i][1]=y-1;
			tong[x-1]=1;
		} else {
			qin[i][0]=y-1;
			qin[i][1]=x-1;
		}
	}
	
	for(int i=0;i<m;i++)
	{
		if(tong[i]==1){
			memset(ans[i],0,sizeof(ans[i]));
			push(i);
			while(begli<=endli){
				now1=pop();
				for(int j=0;j<n+m+1;j++){
					if((ans[i][j]==0 || ans[i][j]>ans[i][now1]+time1[now1][j]) && time1[now1][j]>0){
						ans[i][j]=ans[i][now1]+time1[now1][j];
						push(j);
					}
				}
			}
		}
	}
	
	for(int i=0;i<q;i++){
		cout<<ans[qin[i][0]][qin[i][1]]+w[qin[i][0]]+w[qin[i][1]]<<"\n";
	}
	return 0;
}
