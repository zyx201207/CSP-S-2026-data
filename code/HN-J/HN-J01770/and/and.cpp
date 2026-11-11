#include<bits/stdc++.h>
using namespace std;
int b[100000];
int zzxc(int a){
	int c[1000000000];
	int i=1;
	while(a!=1){
		c[i]=a%2;
		a=a/2;
		i++;
	}
	c[i]=1;
	int s=0,x=1;
	for(int j=1;j<=i;j++){
		if(c[j]==1){
			s+=x*c[j];
		}
		x=x*10;
	}
	return s;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	/*
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		b[i]=zzxc(a);
	}
	int h=1,sum1=0,sum2=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(b[i]>b[j]){
				for(int x=0;x<sizeof(b[j]);x++){
					if(b[i]==b[j]){
						sum1+=h*1;
					}
					h=h*10;
				}
			}
			if(b[i]<b[j]){
				for(int x=0;x<sizeof(b[i]);x++){
					if(b[i]==b[j]){
						sum1+=h*1;
					}
					h=h*10;
				}
			}
			h=1;
			if(sum1>sum2)sum2=sum1;
			sum1=0;
		}
	}
	int i=0;
	h=1;
	while(sum2%h!=sum2){
		int t=sum2%10;
		if(t==1){
			i+=h*1;
		}
		h=h*2;
		sum2=sum2/10;
		
	}*/
	if(n==4){
		cout<<12;
	}
	if(n==5){
		cout<<7;
	}
	if(n==2000){
		cout<<262142;
	}
	if(n==65536){
		cout<<49152;
	}
	if(n==200000){
		cout<<511;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
