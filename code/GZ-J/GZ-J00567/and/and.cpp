//GZ-J00567，邱伟轩，贵阳市乌当第二中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	int m;
	cin>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	int maxbin=0;
	for(int i=0;i<n;i++){
		int x=a[i];
		int y=1;
			for(int k=i;k<n;k++){
				if(y>=m)continue;
				if(i==k)continue;
				x&=a[k];
			}
			maxbin=max(x,maxbin);
	}
	cout<<maxbin;
	return 0;
} 
