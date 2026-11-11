#include<bits/stdc++.h>
using namespace std;
long long a[30005],s[300005],x[2005][2005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
long long n,m;
cin>>n>>m;
for(int i=0;i<n;i++){
	cin>>a[i];
	long long z=1;
	while(a[i]!=0){
		 s[i]+=a[i]%2*z;
		 z=z*10;
		 a[i]=a[i]/2;
	}
}
	for(int i=0;i<n;i++){
		for(int j=1;j<=m;j++){
			 for(int k=i+j;k<n;k++){
			 	long long w=1;
			 	long long s1=s[i],s2=s[k];
			 	if(j>1){
			 		s1=x[i][k-j];
				 }
			 	 while(s1!=0&&s2!=0){
			 	 	if(s1%10==0||s2%10==0){
			 	 		x[i][k-j]+=0;
					  }
					  else{
					  	x[i][k-j]+=1*w;
					  }
					  w=w*10;
					  s1=s1/10;
					  s2=s2/10;
				  }
			 }
		}
	}	
	long long sum=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(x[i][j]>sum){
				sum=x[i][j];
			}
		}
	}
	long long ss=0,t=1;
	while(sum!=0){
		ss+=sum%10*t;
		t=t*2;
		sum=sum/10;
	}
	cout<<ss;

	return 0;
}
