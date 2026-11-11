#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c,u,w,d,p;
	cin>>c>>u>>w>>d>>p;
	string g;
	for(int i=0;i<w;i++){
		cin>>g;
	}
	string a;
	int n,m,q=0,sum=0,hbr=0,wfj=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	if(n/2!=0){
		sum=a[n/2+1-1];
	}else{
		sum=a[n/2-1];
	}
	for(int i=0;i<n;i++){
		wfj=sum-a[i];
		if(a[i]<sum && wfj<m){
			hbr++;
			m=m-(sum-a[i]);
		}
	}
	cout<<hbr;
	cout<<c+u+w+d+p;
	for(int i=0;i<w;i++){
		cout<<g;
	}
	
	
	fclose(stdin);
	fclose(stdout);
} 
