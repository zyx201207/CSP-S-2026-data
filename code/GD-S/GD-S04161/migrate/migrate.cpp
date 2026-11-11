#include<bits/stdc++.h>
using namespace std;
int main()
{
//{5,3,-2,-1,0,1,2,6,2,-4,-3,-2,-1,3,6
	int c,t,a[100005],a1[30]={4,2,1,2,3,4},a2[30]={5,2,1,2,3,4,5};
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		bool x=1,y=1;
		for(int j=1;j<=2;j++){
			cin>>a[j];
		}
		for(int j=3;j<=3+a[1];j++){
			cin>>a[j];
		}
		for(int j=1;j<=6;j++){
			if(a[j]!=a1[j] && x){
				x=0;
			}
			if(a[j]!=a2[j] && y){
				y=0;
			}	
		}
		if(x){
			cout<<1<<endl;
		}
		if(y){
			cout<<2;
		}
	}
	
	
	return 0;
}
