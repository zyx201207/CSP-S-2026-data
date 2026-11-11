#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct str{
	long long p;char q;
}a[N],b[N];
int main(){
	long long n,ans=0;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].p>>a[i].q;
		b[n+1-i].p=a[i].p;
		b[n+1-i].q=a[i].q;
	}
	int c=1,d=1;
	cout<<a[1].q<<" "<<b[1].q;
	while(a[n].p!=0&&b[n].p!=0){
		if(a[c].q!=b[d].q){
			ans+=min(a[c].p,b[d].p);
		}
		if(a[c].p<b[d].p){
			b[d].p-=a[c].p;
			a[c].p=0;
			c++;
		}else if(a[c].p>b[d].p){
			a[c].p-=b[d].p;
			b[d].p=0;
			d++;
		}else{
			a[c].p=0;
			b[d].p=0;
			c++;
			d++;
		}
	}
	cout<<ans/2;
	return 0;
}
