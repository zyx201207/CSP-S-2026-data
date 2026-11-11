#include<bits/stdc++.h>
using namespace std;
int x[200010][32],y[32],l=0,mx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m,c;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		l=0;
		cin>>c;
		mx=max(mx,c);
		while(c>0){
			l++;
			y[l]=c%2;
			c/=2;
		}
	   for(int j=1;j<=l;j++)x[i][j]=y[l];
	}
	if(m==1){
		cout<<mx;
		return 0;
	} 
		
} 
