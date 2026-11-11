#include<bits/stdc++.h>
using namespace std;

	int b[6]={4,2,1,2,3,4};
	int b1[7]={5,2,1,2,3,4,5};
	int b2[7]={5,3,-2,-1,0,1,2};
	int b3[8]={6,2,-4,-3,-2,-1,3,6};
int check(int n,int d,int a[2001]){
	int e=9,e1=9,e2=9,e3=9;
	if(n!=b[0]){
		e=0;
	}
	if(n!=b1[0]){
		e1=0;
	}
	if(n!=b2[0]){
		e2=0;
	}
	if(n!=b3[0]){
		e3=0;
	}
	if(d!=b[1]){
		e=0;
	}
	if(d!=b1[1]){
		e1=0;
	}
	if(d!=b2[1]){
		e2=0;
	}
	if(d!=b3[1]){
		e3=0;
	}
	for(int i=2;i<n;i++){
		if(a[i-2]!=b[i]){
			e=0;
		}
		 if(a[i-2]!=b1[i]){
			e1=0;
		}	
		if(a[i-2]!=b2[i]){
			e2=0;
		}	
		if(a[i-2]!=b3[i]){
			e3=0;
		}		
	}
	if(e==9){
		return 1;
	}else if(e1==9){
		return 2;
	}else if(e2==9){
		return 0;
	}else if(e3==9){
		return 1;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		int n,d;
		cin>>n>>d;
		int a[2001]={};
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		cout<<check(n,d,a)<<endl;
	}

	return 0;
}
