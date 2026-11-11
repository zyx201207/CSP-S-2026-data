#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	int i,j,c1,c2,k,a1,b1;
	char s1[3],s2[3],a[2],b[2],e,f;
	cin>>c1;
	for(i=1;i<=3;i++)
	{
	cin>>s1[i];
	}
	cin>>c2;
	for(j=1;j<=3;j++)
	{
		cin>>s2[j];
	}
	if(c1==c2){
	cout<<1;
	k=1;
	}
	else {
	cout<<0<<0<<0<<0;
	return 0;
	}
	if(k==1){
    for(i=1;i<=2;i++){
	a[i]=s1[i];
	b[i]=s2[i];
	if(a[1]==b[1]&&a[2]==b[2])
	 cout<<1;k=2;}
	}	
	else {
	cout<<0<<0<<0;
	return 0;
	}
	if(k==2){
	e=s1[3];
	f=s2[3];
	a1=e-'0';
	b1=f-'0';
	if(b1-a1>2){
	cout<<0<<0;
	return 0;
	}
	if(a1>18){
	cout<<0<<0;
	return 0;
	}
	else{
	 cout<<1;
	  k=3;
	  }
	}
	if(k==3){
		if(b1-a1==1){
		cout<<1;
		}
	}
	else cout<<0;
	return 0;
}

