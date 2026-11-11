#include<bits/stdc++.h >
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	int s[n];
	char z[n];
	int num=0;
	for(int i=0;i<n;i++){
		cin>>s[i]>>z[i];
		num=num+s[i];
	}
	int b=0;
	if(num%2==1){
		b=num/2+1;
	}
	else{
		b=num/2;
	}
	int f=0;
	if(n%2==1){
		f=f/2+1;
	}
	else{
		f=f/2;
	}
	int w=0;
	for(int i=0;i<f;i++){
		w=w+s[i];
	}
	int x=0,y=n-1;
	long long g=0; 
	for(int i=num;i>b;){
		if(z[x]!=z[y]){
			g=g+min(s[x],s[y]);

		}
		if(s[x]>s[y]){
			s[x]=s[x]-s[y];
			i=i-s[y];
			y--;
		}
		else if(s[x]<s[y]){
			s[y]=s[y]-s[x];
			i=i-s[x];
			x++;
		}
		else{
			i=i-s[x];
			x++;
			y--;
		}
	}
	cout<<g;
}
