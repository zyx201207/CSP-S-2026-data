#include<bits/stdc++.h>
using namespace std;
struct{
	long long s;
	char z;
}a[200005];
int main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,g,sum=0,o=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].s >>a[i].z;
		o=o+a[i].s; 
	}
	long long l=1,r=n-1;
	o/=2;
	for(long long i=0;i<o; ){
		if(a[l].z!=a[r].z ){
			sum+=min(a[l].s,a[r].s);
		}
		i+=min(a[l].s,a[r].s);
		a[l].s-=min(a[l].s,a[r].s);
		a[r].s-=min(a[l].s,a[r].s);
		if(a[l].s==0){
			l++;
		}else{
			r--;
		}
	}
	cout<<sum;
	return 0;
} 
