#include <bits/stdc++.h>
using namespace std;
vector<int> a,f;
vector<vector<int>> b;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,
	cin>>c>>t;
	for(int k=0;k<t;k++){
		long long n,d,s;
		cin>>n>>d;
		a.assign(n,0);
		for(int i=0;i<n;i++)cin>>a[i];
		b.assign(n,vector<int>(n,0));
		for(int i=0;i<n;i++){
			s=0;
			for(int j=i+1;j<n;i++){
				if(s-a[j]+a[j-1]<0){
					b[i][j]=b[i][j-1]+1;
					s=d-a[j]+a[j-1];
				}
				else{
					b[i][j]=b[i][j-1];
					s=s-a[j]+a[j-1];
				}
			}
		}
		for(int i=0;i<n;i++){
			f=b[i];
			for(int j=i+3;j<n;i++){
				if(d[i][j]>2){
					for(int v=i+1;v<j;v++){
						if(a[i][v-1]==a[i][v]){
							s=d-a[j]+a[j-1];
							for(int l=v+1;j<n;i++){
								if(s-a[j]+a[j-1]<0){
									b[i][j]=b[i][j-1]+1;
									s=d-a[j]+a[j-1];
								}
								else{
									b[i][j]=b[i][j-1];
									s=s-a[j]+a[j-1];
								}	
							}
						}
					}
				}
			}
		}
	} 
}
