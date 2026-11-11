//GZ-J00703      高再蕤           遵义市第四初级中学 
#include <bits/stdc++.h>
using namespace std;
int mg(long long a){
	int b=0,i=1;
	while(a!=0){
		b=b+a%2*i;
		a=(a-a%2)/2;
		i=i*10;
	}
	return b;
}
int hg(long long a,long long b){
	int c=0,i=1;
	while(a!=0||b!=0){
		if(a%10==b%10){
			c=c+1*i;
		}
		i=i*10;
		a=a/10;
		b=b/10;
	}
	return c;
}
int gm(long long a){
	int b=0,i=1;
	while(a!=0){
		b=a%10*i;
		a=a/10;
		i=i*2;
	}
	return b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[100001],b[100001],x=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i;j++){
			if(gm(hg(mg(a[i]),mg(a[j])))>x){
				x=gm(hg(mg(a[i]),mg(a[j])));
			}
			
		}
	}
	if(n==1){
		cout<<a[0];
	}else{
		cout<<x;
	}
	return 0;
}

