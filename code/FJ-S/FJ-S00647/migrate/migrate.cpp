#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d,ans;
int x[2000006],xc[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	
	for(int k=1;k<=t;k++){
	    cin>>n>>d;
	    int num=0,m=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			if(i==1) num=x[i+1]-x[i];
			xc[i]=x[i+1]-x[i];
			if(xc[i]!=num) m=1; 
		}
		if(m==1){
		int sum;
		sum=d/num;
		for(int i=1;i<=n;i++){
			for(int j=i+sum;j<=n;j++){
				if((j-i)%sum!=0) ans++;
			}
		}
		cout<<ans<<"\n";	
		}else{
			cout<<0;
		}
		ans=0;
	}
	
	return 0;
}
