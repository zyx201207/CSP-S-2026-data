#include<iostream>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	long long p=1;
	for(int i=1;i<=n;i++){
		if(m!=0){
			if(i*(a[i+1]-a[i])<=m){
				if(i*(a[i+1]-a[i])<0){
					m=m+i*(a[i+1]-a[i]);
					p+=1;
				}
				else{
					m=m-i*(a[i+1]-a[i]);
					p+=1;
				}
			}
		}
		if(a[i+1]==a[i+2]){
				p+=1;
				break;
		};
	}
	cout<<p;
	return 0;
} 
