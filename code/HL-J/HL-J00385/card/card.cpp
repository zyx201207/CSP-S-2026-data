#include<bits/stdc++.h>
using namespace std;
int n,m,num=0;
int main(){	
int a[n];
cin>>n;
freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
for(int c=0;c<m;c++){

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i]==a[j])
{
	for(int b=j;b>0;b--)
	{
		a[0]=a[b];num+=1;
	}
		}		}
	}
	cout<<num;
	}
	}
