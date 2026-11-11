#include<bits/stdc++.h>
using namespace std;
long long c=0,n=0,m=0,d=0,q=0;
struct sattion{
	int enter=0;
	int zhuan=0;
	int can[100005]={0};
	int time[100005]={0};
	int all=0;
};
sattion sta[100005];
struct ji{
	int x=0;
	int y=0;
};
ji plan[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>sta[i].enter;
	}	
	for(int i=0;i<n;i++){
		int k=0;   
		cin>>k;
		sta[i].all=k;
		for(int j=0;j<k;j++){
			cin>>sta[i].can[k]>>sta[i].time[k];
		}
	}
	for(int i=0;i<q;i++){
		cin>>plan[i].x>>plan[i].y;
	}
	fclose(stdin);
	fclose(stdout);
	
} 
