#include<bits/stdc++.h>
using namespace std;
struct node{
	char m,n;
	long long a,b,c;
};
long long adj[1000000];
node adv[100000];
int main(){
	long long a,b,c,i,j,m,n,k,y,z;
	char t;
	string x;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	c=k=y=z=0;
	for(i=0;i<a;i++){
		cin>>b>>t;
		c+=b;
		if(c<10000){
		
		for(j=0;j<b;j++){
			x=x+t;
		}
		
		
	}
	else{
		y=1;
	}	
		adv[i].m=t;
		adv[i].a=b; 
	//	cout<<1;
	}
	//c/=2;
	if(y==1){
	
	j=0;
	for(i=a-1;i>=a/2;i--){
		if(adv[i].m != adv[a-1-i].m){
			j+=min(adv[i].a,adv[a-1-i].a);
	} 
}
	cout<<j;
}

else{

	
	m=0;
	for(i=0;i<c/2;i++){
		if(x[i]!=x[c-i+1]){
		m++;	
		}
	//	cout<<x[i]<<" "<<x[c-i-1]<<" ";
	}

	cout<<m;
}
	return 0;
} 
