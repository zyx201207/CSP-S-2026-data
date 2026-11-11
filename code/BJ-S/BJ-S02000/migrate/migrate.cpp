#include<bits/stdc++.h>
using namespace std;
int bx,dx,dy;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.o","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d,x[5005],sum=0;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		for(int i=0;i<n;i++){
			if(dy==bx){
				sum++;
			}
			int bx=x[i];
			dx=bx;
			for(int j=i+1;j<n;j++){
				if(abs(bx-x[j])<=d){
					bx=x[j];
				}
			}
			dy=bx;
		}
		cout<<sum<<endl;
	}
	return 0;
}
