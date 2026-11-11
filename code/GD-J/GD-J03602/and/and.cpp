#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a[100000],b,c,d=0;
	cin>>b>>c;
	for(int i=0;i<b;i++){
		cin>>a[i];
	}
	for(int i=b-1;i>=0;i--){
		
	for(int j=0;j<i;j++){
		if(a[j]<a[j+1])
		{
			d=a[j];
			a[j]=a[j+1];
			a[j+1]=d;
		}

    }
	}
	cout<<a[c-1];
	return 0;
 } 
