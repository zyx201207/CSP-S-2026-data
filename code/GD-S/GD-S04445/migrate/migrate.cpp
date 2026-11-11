#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c;
	cin>>t;
	while(t--){
		long long n,d,sum=0;
		cin>>n;
		cin>>d;
		long long x[n+10],a[n+10][n+10];
		bool b[n+10][n+10];
		memset(a,0xf,sizeof(a));
		memset(b,1,sizeof(b));
		for(long long i=1;i<=n;i++) {
			cin>>x[i];
			for(long long j=1;j<i;j++){  //j出发点，i终点 
				if(x[i]-x[j]<=d) a[j][i]=1;
				else 
				if(j!=i-1 && x[i]-x[i-1]<=d){
					int l=1;
					while(x[i]-x[i-l]<=d){
						a[j][i]=min(a[j][i-l]+1,a[j][i]);
						l++;
				}
					if(x[i]-x[i-2]<=d && a[j][i-1]==a[j][i-2] && !(x[i]-x[i-3]<=d && a[j][i-1]==a[j][i-3] && i>3 && i-3>j) ){
						if(b[j][i]){
						b[j][i]=0;
						sum++;
						}
						else sum--;
					}
				}
			}
		} 
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
