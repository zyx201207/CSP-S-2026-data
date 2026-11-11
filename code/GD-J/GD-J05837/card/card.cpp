#include<bits/stdc++.h >
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long q[n];
	long long a[n];
	for(long long h=0;h<n;h++){
		cin>>a[h];
	}
	long long f[n][n];
	for(long long y=1;y<=n;y++){
		for(long long s=0;s<n;s++){
			if(s<y){
				f[y-1][s]=0;
			}
			else{
				f[y-1][s]=a[s];
			}
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long h=i-1;h<n;h++){
			for(long long d=h+1;d<n;d++){
			 if(f[i-1][h]==f[i-1][d]){
			 	for(int j=h;j<d;j++){
			 		f[i-1][j]=0;
				 }
				 h=d-1;
				 break;
			}
			 }
		}
	}
		for(int y=0;y<n;y++){
			for(long long pc=0;pc<n;pc++){
				if(f[y][pc]!=0){
					q[f[y][pc]-1]++;
				}
			}
		}
	for(int w=0;w<n-1;w++){
		cout<<q[w]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
