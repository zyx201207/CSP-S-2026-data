#include<bits/stdc++.h> 
using namespace std;
int n,m,a[2*100010],v[2*100010],ans=0;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if((n<=5000&&m<=3000)||(m>3000&&n>5000)){
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	for(int i=1;i<m;i++){
		cout<<0<<" ";
	}
	cout<<n;
}
    else if(m==1){
    	for(int i=1;i<=n;i++){
			cin>>a[i];
		}
    	cout<<n;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		v[a[n]]=n;
		for(int i=1;i<m;i++){
			cout<<v[i]<<" ";
	    }
	}
    else{
    	for(int i=1;i<=n;i++){
			cin>>a[i];
			v[a[i]]=i;
		}
    	for(int i=1;i<m;i++){
		cout<<v[i]<<" ";
	    }
	}
	return 0;
}

