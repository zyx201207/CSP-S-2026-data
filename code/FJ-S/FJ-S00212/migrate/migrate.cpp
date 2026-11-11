#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d;
long long a[200005];
int mn=2000000000;
int qwe[200000000];
void dfs(int fom,int too,int step){
	if(fom==too){
		mn=min(mn,step);
		qwe[step]++;
		return;
	}
	for(int i=fom+1;i<=too;i++){
		if(a[i]-a[fom]<=d){
			dfs(i,too,step+1);
		}
	}
}
void f(){
	cin>>n>>d;
	int nqdpy=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=0;k<200000000;k++){
				qwe[k]=0;
			}
			dfs(i,j,0);
			if(qwe[mn]==2){
				nqdpy++;
			}
		}
	}
	cout<<nqdpy<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	cin>>c>>t;
	for(int i=0;i<t;i++){
		f();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
crystal





*/
