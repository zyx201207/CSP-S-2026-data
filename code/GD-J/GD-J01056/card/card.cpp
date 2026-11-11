#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000001],ij=1,ans,c[1000001],d[1000001],csg[1000001];
int main(){
	freopen("card.in","r",stdin);
  	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}ans=n;
	while(ans--){
		string b;
		long long qi=0,num=0;
		for(int i=ij;i<=n;i++){
		
			long long sf=0;
			for(int j=0;j<=b.size()+1;j++){
				if(b[j]==char(a[i])){
					sf=1;
					b[j]='s';
				}if(sf!=0){
					b[j]='s';
				}
			}b+=char(a[i]);
			}
		for(int i=0;i<b.size();i++){
			if(b[i]!='s'){
				d[int(b[i])]++;
			}
		}
		ij++;}
	for(int i=1;i<=n;i++){
		if(csg[a[i]]==0){
			cout<<d[a[i]]<<" ";
	    	csg[a[i]]++; 
		}
	}
    return 0;
}

