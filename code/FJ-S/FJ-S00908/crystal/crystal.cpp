#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],r,l=1,b[500005],x;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	if(n%2==0) r=a[n/2];
	else r=a[n/2+1];
	x=r;	
	for(int i=1;i<=n;i++){
		b[i]=abs(x-a[i]);
	}
	sort(b+1,b+1+n);
	while(m>0){
		for(int i=1;i<=n;i++){
			if(m>b[i]&&m-b[i]>=0){
				m-=b[i];
				l++;
			}else {
				cout<<l;
				return 0;	
			}
		}
	}
	
}
