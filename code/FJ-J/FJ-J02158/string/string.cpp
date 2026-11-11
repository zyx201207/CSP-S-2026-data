#include<bits/stdc++.h>
using namespace std;
int man(){
int n,a[200010]={0},b,c,d,k,j,u,i;
int x=0,y=0,z=0;
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(int i=0;i<n;i++)
{
	cin>>a[i]>>b;
	z=z+a[i];
}
    c=z/2;
    d=z/2+z%2;
    for(int i=0;i<c;i++){
    	k=i;
    	long long j=0,u=n-1;
    }
    	while(k>=a[j])
    	k=k-a[j];
    	j++;
		while(k>=a[j])
		k=k-a[u];
		u--;
		if(j==b)
		y++;
        cout<<"x,y";
    }

