#include<bits/stdc++.h>
using namespace std;
int d(int a){
	int p=0;
	while(a==0){
		p*=10;
		p+=a%2;
		a/2;
		
	}
	return p;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	for(int i=0;i<n;i++){
		a[i]=d(a[i]);
		cout<<a[i]<<endl;
	}
	int v[200]={0};
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[j]>v[i] && (i!=0 && a[j]<v[i-1])){
				v[i]=a[j];
			}
		}
	}
	int f=0;
	for(int i=0;i<m;i++){
		f+=v[i];
	}
	int h=0;
	int x=0;
	while(f==0){
		h=f%10*2^x;
		f/=10;
		x++;
	}
	cout<<h;

	return 0;
}
