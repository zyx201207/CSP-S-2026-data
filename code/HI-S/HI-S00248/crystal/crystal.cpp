#include<bits/stdc++.h>
using namespace std;
const int N=2e5+6;
long long m,n=1,k,a[N],xy,b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		k+=a[i];
	}
	long long q=k/n;
	long long kk=abs(a[1]-q);
	for(int i=1;i<=n;i++){
		if(kk>abs(a[i]-q)){
			kk=abs(a[i]-q);
			xy=i;
		}
	}
	for(int i=1;i<=n;i++){
		b[i]=abs(a[i]-a[xy]);
	}
	sort(b+1,b+n);
	int lun=1;
	while(m>0){
		m=m-b[lun];
		lun++;
	}
	cout<<lun-1;
	return 0;
} 
