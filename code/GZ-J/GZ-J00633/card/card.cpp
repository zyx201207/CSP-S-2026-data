//GZ-J00633,贵阳市清华中学，李明星
#include<bits/stdc++.h>
using namespace std;
int a[10086];
int b[10086];
int main(){\
	freopen("card.in","r",stdin);
	freopen("card.out","r",stdout);
	int m,n,x,j=0;
	cin>>n>>m;
	for(int i;i<n;i++){
	cin>>a[i];
	while(a[i]!=x){
		
		b[i]=a[i];
		x=a[i];
			
	} 
	}
	for(int m=1;m<n;m++){
		cout<<b[m];
	}
	return 0;
} 
