#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	bool pc[n][m];
	bool pz[m];
	int gz[m];
	int ps[n];
	int pj[m+1];
	for (int i=0;i<n;i++){
		cin>>ps[i];
	}
	for(int i=0;i<n;i++){
		pj[0]=0;
		for(int j=0;j<m;j++){
			pz[j]=0;
			pc[i][j]=0;
			gz[j]=0;
		}
		for(int j=i;j<n;j++){
			int c=1;
			if(pz[ps[j]-1])c=0;
			if(c){
				if(pc[i][ps[j]-1]){
					for(;pj[pj[0]+1]==ps[j];pj[0]--);
				}else{
					pj[pj[0]+1]=ps[j];
					pj[0]++;
					pc[i][ps[j]-1]=1;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(pc[i][j]){
				gz[j]+=1;
			}
		}
	}
	for(int i=0;i<m;i++){
		cout<<gz[i]<<" ";
	}
	return 0;
}

