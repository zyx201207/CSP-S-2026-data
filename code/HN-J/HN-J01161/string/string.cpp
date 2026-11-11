#include<bits/stdc++.h>
using namespace std;
long long int n,s,x,num;
struct jf{
	long long t;
	char h;
};
jf a[20000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].t>>a[i].h;
	for(int i=1;i<=n/2;i++){
		if(a[i].h!=a[n-i+1].h){
			int max1=max(a[i].t,a[n-i+1].t),min1=min(a[i].t,a[n-i+1].t);
			s=s+min1;
			x=x+max1-min1;
		} 
	}  
	num=s+x;
	cout<<num;
	return 0;
}
