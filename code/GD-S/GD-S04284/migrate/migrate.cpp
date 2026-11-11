#include<bits/stdc++.h>
using namespace std;
long long x[2000000];
int minn(int l,int r,int f,int time){
	if(l>=r){
		return time;
	}
	for(int i=f;i>0;i--){
		for(int j=f;j>0;j--){
			if(x[l+j]==x[l]+i){
				return minn(l+j,r,f,time+1);
			}
		}
	}
}
int a(int l,int r,int f,int minlong){
	long long x1[r-l][f];
	for(int i=l;i<r;i++){
		for(int j=1;j<f;j++){
			if(x[i]==x[l]+j){
				x1[i-l][j]=x[l]+j;
			}
		}
	}
	int way=0;
	for(int i=1;i<f;i++){
		for(int j=0;j<r-l;){
			int time=0;
			for(;x1[j][i]!=r;j++){
				time++;
			}
			if(time==minlong){
				way++;
			}
		}
	}
	return way;
}
int main(){
	freopen("migrate.in","r",stdin);
	
	long long c,t,n,d;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		for(int j=0;j<n;j++){
			cin>>x[j];
		}
		int minlong=INT_MAX;
		int way=0;
		for(int j=0;j<n-3;j++){
			for(int k=j+3;k<n;k++){
				minlong=min(minlong,minn(j,k,d,0));
				if(a(j,k,d,minlong)==2){
					way++;
				}
			}
		}
	
		freopen("migrate.out","w",stdout);
		cout<<way+1<<endl;
	}
}
