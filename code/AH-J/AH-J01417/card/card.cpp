#include<bits/stdc++.h>
using namespace std;
long long a[1000001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long m,n;
    cin>>m>>n;
    for(long long i=1;i<=m;i++){
		cin>>a[i];
	}
			for(long long y=m;y>=1;y--){
				for(long long z=m;z>=y;z++){
					for(int j=1;j<=n;j++){
						int f=0;
						if(a[z]==j){
							f++;
						}
						cout<<f<<" ";
					}
				}
				
			}
    return 0;
}
