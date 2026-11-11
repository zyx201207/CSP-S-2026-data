#include<iostream>
using namespace std;
int n,m;
int n0;
bool flagA=true;
int a[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	n0=n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i>0){
			if(a[i]<a[i-1])
                flagA=false;
		}		
	}
    for(int i=0;i<m;i++){
    	cout<<n-i<<' ';
	}
	return 0;
}
