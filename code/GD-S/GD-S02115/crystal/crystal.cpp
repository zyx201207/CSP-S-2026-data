#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a[500100];
	long long n,i,z,j=0,p=0,c=1,d=1,h;
	long long m;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	z=a[n/2];
	for(i=n/2-1;i>=0;i--){
		if(a[i]==z){
			c++;
		}else{
			break;
		}
	}
	for(i=n/2+1;i<n;i++){
		if(a[i]==z){
			c++;
		}else{
			break;
		}
	}
	for(i=n/2-1;i>=0;i--){
		if(z-a[i]<=m){
			p=1;
			m-=z-a[i];
			j++;
		}
		if(m<=0){
			if(p==1){
				cout<<j+c;
				return 0;
			}else{
				cout<<0;
			}
		}
	}
	for(i=n/2;i<n;i++){
		if((a[i]-a[i-1])*i<=m){
			m-=(a[i]-a[i-1])*i;
			j++;
		}else{
			break;
		}
	}
	if(p==1){
		cout<<j+1;	
	}else{
		cout<<0;
	}
	return 0;
}
