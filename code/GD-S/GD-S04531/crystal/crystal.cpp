#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long int m;
	int a[100050];
	long long int b[100050];
	cin>>n>>m;
	for(int i=1;i<=n;n++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		b[i]=b[i-1]+(a[i]-a[i-1]*(i-1));
	    	if(d!=a[i]-a[i-1]){
		}
	}
	if(k==0){
		if(d<0){
			d=0=-d;
		}
		for(int i=1;i<=n;i++){
			long long h=i*(d+d*i);
			cout<<h<<' ';
			if(h<=m){
				p=h;
			}else{
				break;
			}
		}
		cout>>p;
		return 0;
	}
	int t=1
	for(int i=1;i<=n;i++){
		for(int j=i1;j<=n;j++){
			long long int b[j]-b[i];
			if(l<m){
				t=max(t,a[j]-a[i]+1);
				break;
			}
		}
	}
	cout<<t;
	return 0;
}
