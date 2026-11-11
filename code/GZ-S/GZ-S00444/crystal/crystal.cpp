//GZ-S00444  贵州省松桃民族中学  龙鑫鑫 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	 for(int i=1;i<=n;i++){
	 	int t;
	 	if(a[i]>a[i+1]){
	 		t=a[i];
	 		a[i]=a[i+1];
	 		a[i+1]=t;
		 }
	 }
	 
	 int c=0;
	 int s=0;
	 int y=n/2+1;
	for(int i=1;i<=n;i++){
		s+=a[y-i]; 
		c++;
		if((s+m)/c==a[y]){
			break;
		} 
	}
	int i=1;
	while(a[y]==a[y+i]){
		i++;
		c++;
		
	}
    cout<<c+1;
	return 0;
} 
