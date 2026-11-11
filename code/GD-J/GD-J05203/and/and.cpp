#include<bits/stdc++.h>
using namespace std;
int pd(int x,int y){
	int x1=max(x,y);
	int x2=min(x,y);
	int d,e=0;
	while(x2!=0){
		if(x1%10==1&&x2%10==1){
			d+=pow(10,e);
		}
		e++;
		x2/=10;
		x1/=10;
	}
	return d;
}
int main(){
	freopen("and.in",'r',stdin);
    freopen("and.out",'w',stdout);
	int m,n,a[200001],b[200001],w=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int l=a[i],s=0;
		while(l!=0)
		{
			b[i]+=l%2*pow(10,s);
			s++;
			l/=2;
		}
		
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int r=pd(b[i],b[j]);
			if(r>w) w=r;
			
		}
		
	}
	cout<<w<<' ';
	int f=0,z=0;
	while(w!=0){
		z+=w%10*pow(2,f);
		f++;
		w/=10;
	}
	cout<<z;
}
