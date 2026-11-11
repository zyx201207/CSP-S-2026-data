#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
  	freopen("crystal.out","w",stdout);
int n,m;
cin>>n>>m;
long long a[100000];
int ans=0;
int sum=0;
long long b[100000];

int bn=0;
for(int i=0;i<n;i++){
	cin>>a[i];
}
for(int i=0;i<n;i++){

for(int j=0;j<i+1;j++){
	


	if(m!=0){
	if(a[j]<=a[i]){
	bn=a[i];
	a[j]=bn;
	m-=1;
	}
	
	}
	
	
}
}
for(int i=0;i<=n;i++){
	if(a[i]==a[i+1]){
		sum+=1;
	}
}
	 cout<<sum;
	 return 0;
}
	


