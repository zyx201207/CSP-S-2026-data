#include<bits/stdc++.h> 
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a[10000]={},b[10000]={},q=0,w=0,half=0,v=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n%2==0){
		half=n/2;
	}
	else{
		half=n/2;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			q=a[i];
			if(q<=a[j]){
				w=a[i];
				a[i]=a[j];
				a[j]=w;
				q=a[j];
			}
		}
	}
	for(int i=0;i<n;i++){
		b[i]=a[i]-a[half];
	}
	for(int i=0;i<n;i++){
		if(m>=0&&(b[i]<=m)){
			m+=b[i];
			v++;
		}
	}
	cout<<v;
	return 0;
}

	
