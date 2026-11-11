#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],b[200005],c;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int cnt =0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if (m==2){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			b[cnt]=a[i]&a[j];
			cnt++;
			
		}}
      	sort(b,b+cnt); 
		cout<<b[cnt-1];
	 }
	else {
		for(int i=0;i<n;i++){
			b[cnt]=a[i];
			cnt++;}
			
      	sort(b,b+cnt); 
		cout<<b[cnt-1];
	 }
	
	
	return 0;
} 
