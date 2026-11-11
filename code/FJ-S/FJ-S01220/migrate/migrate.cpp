#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t;
int jl[6000][6000];
int lj[6000][6000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int cnt=0;
		int n,d;
		int a[100000];
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
			    jl[i][j]=a[j]-a[i];
		    }
		}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
			    int r=i+1;int l=i;
			    int ant=0;
			    while(r<=j){
				     if(jl[l][r]>=d){
				     	ant++;
				     	l++;
					 }else{
					 	r++;
					 }
				}
				if(ant==2){
					cnt++;
				}
	        }
		}
		cout<<cnt<<endl;
	}
	return 0;
}
