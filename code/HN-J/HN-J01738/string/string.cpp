#include<bits/stdc++.h>
using namespace std;
int a,b,g;
char add[1123],ahh[1123];
	int abb[1123];
	long long acc=0,c;
int main(){
	freopen("string2.in","r",stdin);
		freopen("string.out","w",stdout);
		cin>>a;
for(int i=1;i<=a;i++){
	cin>>abb[i]>>ahh[i];
}
b=a/2;
g=a;
a=0; 
for(int i=1;i<=g;i++){
	a=a+abb[i];
}
acc=0;
if(a%2==0){
	b=a/2;
	for(long long i=b;i<=b;i++){
		add[i]=ahh[i];
	}
	for(long long j=0;j<=b;j++){
		if(ahh[j]!=add[j+b]){
			acc++;
		}
	}
	cout<<acc;
}else{
	b=(a-1)/2;
	for(long long i=b+1;i<=a;i++){
		add[i]=ahh[i];
	}
	for(long long j=0;j<=b+1;j++){
		if(ahh[j]!=add[j+b+1]){
			acc++;
		}
	}
	cout<<acc;
} 
	return 0;
}
