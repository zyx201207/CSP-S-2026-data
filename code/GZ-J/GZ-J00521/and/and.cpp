//GZ-J00521 ÍõÐÞÆë 
#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],maxx=-1,s=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]>maxx) maxx=a[i];
	}
	
	return 0;
}
