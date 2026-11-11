#include<bits/stdc++.h>
using namespace std;
long long n,c=0,cnt=0;
struct S{
	long long q;
	char w;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].q>>a[i].w;
		cnt+=a[i].q;
	}
	cnt/=2;
	long long l=1,r=n,op=0,pp=0;
	while(op<cnt&&pp<cnt){
		if(a[l].q==0){
			l++;
		}
		if(a[r].q==0){
			r--;
		}
		long long re=min(a[l].q,a[r].q);
		op+=re;
		pp+=re;
		a[l].q-=re;
		a[r].q-=re;
		if(a[l].w!=a[r].w){
			c+=re;
		}
	}
	cout<<c;
	return 0;
} 
