#include<bits/stdc++.h>
using namespace std;
int n,m,qp,dx[6]={0,1,0,-1},dy[6]={1,0,-1,0},a[1000000],wz=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int jl;char c;
		cin>>jl>>c;
		for(int j=wz;j<=wz+jl;j++){
			a[j]=c-'a'+1;
		}
		
		wz+=jl; 
	}int cd=wz,ans=0;
	for(int i=1;i<=cd/2;i++){
	 if(a[i]!=a[cd-i+1])ans++;
	} 
	
	
	
	
	
	
	cout<<ans;
	




	
	
	
	
	
	return 0;
}
