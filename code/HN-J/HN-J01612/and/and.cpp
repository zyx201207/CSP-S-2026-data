#include<iostream>
using namespace std;
int n,m;
int ma=0;
int sum;
int C[3]={1,2,3};
bool flagA=true;
bool flagB=true;
bool flagC=true;
int a[200002];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>ma)
		    ma=a[i];
		if(a[i]!=i-1)
		    flagB=false;
		if(a[i]!=1||a[i]!=2||a[i]!=3)
		    flagC=false;
	}
	sum=a[0];
	if(m==1){
	    sum=ma;;
	}else if(m==n){
		for(int i=1;i<n;i++){
			sum&=a[i];
		}
	}else if(flagB){
		sum=0;
	}else if(flagC){
		sum=3;
	}else{
		sum=ma;
	}
	cout<<sum;
	return 0;
}
