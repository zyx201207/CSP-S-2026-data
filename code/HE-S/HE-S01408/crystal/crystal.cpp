#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,f;
	long long m,mi=1e+12;
	bool di=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	while(m>=0){
		for(int i=1;i<=n-1;i++){
			if(a[i]!=a[i+1]){
				di=1;
				break;
			}
		}
		if(di==0){
			break;
		}
		for(int i=2;i<=n;i++){
			if(a[i]-a[i-1]>0&&a[i]-a[i-1]<mi){
				mi=a[i]-a[i-1];
				f=i-1;
			}
		}
		if(m-mi>=0){
			a[f]=a[f]+mi;
			m=m-mi;
			mi=1e+12;
			di=0;
		}
		else{
			break;
		}
	}
	int p=1,ma=1;
	for(int i=1;i<=n-1;i++){
		if(a[i]==a[i+1]){
			p++;
			if(p>ma){
				ma=p;
			}
		}
		else{
			p=1; 
		}
	}
	cout<<ma;
	
	return 0;
}
