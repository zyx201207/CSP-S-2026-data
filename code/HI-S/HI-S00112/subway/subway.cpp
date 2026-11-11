#include <bits/stdc++.h>
using namespace std;
struct zn{
int sta;
int time;
int bc[50005];
}z[50005];//tai to ting
int main(){
	freopen("subway","r",stdin);
	freopen("subway","w",stdout);
int c,n,m,d,p,all=0;
cin>>c>>n>>m>>d>>p;
int wt[50005],end=0,start=0,mm=0,js[50005];
int guo[50005];
int bian=0;

bool flag=false,pd=false;
for(int i=0;i<m;i++){
	cin>>wt[i];
}
for(int i=0;i<n;i++){
	cin>>guo[i];
	for(int j=0;j<guo[i];j++){
		js[i]++;
		cin>>z[j].sta>>z[j].time;
	}
}

for(int jh=0;jh<p;jh++){
	cin>>start>>end;	
	pd=0;
	all=0;
	mm=0;
	//ks
	for(int i=0;i<n;i++){
		for(int j=0;j<guo[i];j++){
		
		if(z[j].sta==start){
			all+=(wt[start]+z[mm*guo[i]+j].time);
			cout<<all<<endl;
			
		}
	}
	mm+=1;
	}
//zd
for(int i=0;i<n;i++){
	for(int j=0;j<guo[i];j++){
		if(start==z[j].sta){
			flag=1;
			bian=z[j].sta;
		}
	}
		for(int j=0;j<guo[i];j++){
		if(end==z[i].sta&&flag==1){
			pd=1;
			cout<<wt[bian]+z[bian].time+z[i].time+wt[i];
		}
	}
}
if(pd==1){
	break;
}
//hc
for(int i=0;i<n;i++){
	for(int j=1;j<n;j++){
		if(z[i].sta==z[j].sta){//j xian
			for(int kk=0;kk<guo[j];kk++){
				if(z[kk].sta==end){
					all+=(z[i].time+z[j].time)+wt[end]+z[end].time;
				} 
			}
		}
	}
}
cout<<all<<endl;
}

	return 0;
}

