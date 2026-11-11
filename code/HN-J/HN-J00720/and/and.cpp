#include<iostream>
using namespace std;
int n,m;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		long long maxx=0;
		for(int i=1;i<=n;i++){maxx=max(maxx,a[i]);}
		cout<<maxx;
	}
	if(m==n){
		long long m=a[1];
		for(int i=2;i<=n;i++){m&=a[i];}
		cout<<m;
	}
	if(m==2){
		long long maxx=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
			maxx=max(maxx,a[i]&a[j]);
		}}
		cout<<maxx;
	}
	if(m=n-1){
		long long maxx=0;
		for(int i=1;i<n;i++){
			int an=0;
			for(int j=1;j<=n;j++){
				if(i==j){continue;}
				else if(an==0){an=a[j];}
				else{an&=a[j];}			
			}
		maxx=max(maxx,an);
		}
		cout<<maxx;
	}
	else{cout<<0;}
	return 0;
}
