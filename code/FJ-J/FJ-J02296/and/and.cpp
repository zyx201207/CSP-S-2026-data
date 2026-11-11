#include<bits/stdc++.h>
using namespace std;
int a[200005][105],e[100005],x[100005][100005],p[200005];
int i,z=1,ans;
int f(int b){
	for(int j=1;b!=0;j++){
		a[i][j]=b%2;
		b=b/2;
		p[i]=j;
	}
}
int h(int c,int d){
	for(int j=1;j<=d;j++){
		x[1][j]=j;
	}
	for(int j=1;true;j++){
		for(int k=1;k<=d;k++){
			if(x[j][k]>=c){
				x[j][k-1]++;
				x[j][k]=x[j][k-1]+1;
				break;
			}
			else{
				for(int l=1;l<d;l++){
					if(l+1==d&&d>2){
						int v=x[j][l+1];
						e[z]=g(ans,v);
						z++;
					}
					else if(l+1==d){
						e[z]=g(x[j][l],x[j][l+1]);
					}
					else if(l==1){
						ans=g(x[j][1],x[j][2]);
					}
					else{
						ans=g(ans,x[j][l+1]);
					}
				}
			}
		}
	}
}
int g(int c,int d){
	int t;
	if()
	for(int j=1;j<=t;j++){
		
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int c,d,b;
	cin>>c>>d;
	for(i=1;i<=c;i++){
		cin>>b;
		f(b);
	}
	h(c,d);
	return 0;
}
