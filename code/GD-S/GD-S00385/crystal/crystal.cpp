#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long eval[500003];
long long lst[500003][3];
bool comp_bj(int x,int y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>eval[i];
	}
	sort(eval,eval+n,comp_bj);
	long long lasv=-1e14,arr=-1;
	for(int i=0;i<n;i++){
		if(eval[i]!=lasv){
			lasv=eval[i];
			arr++;
			lst[arr][0]=eval[i]; 
			lst[arr][2]=i;
		}
		lst[arr][1]++;
	}
//	for(int i=0;i<=arr;i++){
//		cout<<lst[i][0]<<"-"<<lst[i][1]<<"-"<<lst[i][2]<<"\n";
//	}
	
	long long cpmax=0;
	for(int i=0;i<=arr;i++){
		long long step_used=0,curmax=0;
		for(int j=i-1;j>=0;j--){
			step_used+=(lst[i][0]-lst[j][0])*lst[j][1];
			curmax+=lst[j][1];
			if(step_used>m){
				long long curgap0=step_used-m;
				long long dlt=(lst[i][0]-lst[j][0]);
				curmax-=curgap0/dlt;
				if(curgap0%dlt>0)
				curmax--;
				break;
			}
		}
		
		int at4=0;
		for(int k=0;k<=i;k++){
			at4+=lst[k][1];
		}
		
		if(curmax>=0){
			curmax+=lst[i][1];
		//cout<<"TGT="<<lst[i][0]<<",cost"<<step_used<<"/"<<m<<",cbcnt="<<curmax<<"/"<<at4<<"\n";
		cpmax=max(cpmax,curmax);	
		}
		
	}
	cout<<cpmax<<"\n";
	
	return 0;
} 
