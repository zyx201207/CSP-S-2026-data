#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,T=1;
	int w[20000];
	int k[510],a[510][400],t[510][400],x[10000],y[10000];
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	while(T<=q){
		cin>>k[T];
		for(int i=1;i<=k[T];i++){
			cin>>a[T][i]>>t[T][i];
		}
		T++;
	}
	T=1;
	while(T<=q){
		cin>>x[T];
		cin>>y[T];
		T++;
	}
	int sum;
	T=1;
	while(T<=q){
	    for(int i=1;i<=q;i++){
     		sum=w[x[i]]+w[y[i]];
    		for(int j=1;j<=k[i];j++){
    			if(a[i][j]==x[i]){
    				sum=sum+t[i][j]+t[i][j+1];
				}
				if(a[i][j]==y[i]){
					sum=sum+t[i][j]+t[i][j-1];
				}
			}
    	}
    	cout<<sum<<endl;
    	sum=0;
    	T++;
    }
    
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
