#include<bits/stdc++.h>
using namespace std;
int f1(int x){
	int t=0;
	for(int i=0;i<999999999;i++){
		if(x==1){
			t+=pow(10,i);
			break;
		}
		if(x==2){
			t+=pow(10,i+1);
			break;
		}
		t+=x%2*pow(10,i);
		x=x/2;
	}
	return t;
}
int main(){
   freopen("and.in","r",stdin);
   freopen("and.out","w",stdout);
   int n,m,a[200001],min=0;
   cin>>n>>m;
   for(int i=1;i<=n;i++){
	    cin>>a[i];
	    if(a[i]>min) min=a[i];
   }
   cout<<min;
   return 0;
}
