#include<bits/stdc++.h>
using namespace std;
long long n,m,maxx,a[200005],b[200005];
char c[200005][200],cc[200005][200];
int main(){
	cin>>n,m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=1;j<=a[i];j*=2){
			if(a[i]/j<=1){
				for(int z=j,k=0;z>0;z/=2,k++){
					if(a[i]/j==1) c[i][k] = 1;
					maxx = max(maxx,k);
				}
				break;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int z=0;z<=maxx;z++){
				if(c[i][z]==1&&c[j][z]==1)
					cc[i][z] = 1;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=maxx;j>=0;j--){
			if(cc[i][j]==1) b[i] = j;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<=maxx;j++){
			
		}
	}
	return 0;
}
