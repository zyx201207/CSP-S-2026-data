#include<bits/stdc++.h>
using namespace std;
long long n,k[67],s,h,sum=0;
char a[67];
int main(){
	freopen(read,"string.in","r");
	freopen("string.ans","w");
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>k[i]>>a[i];
		h+=k[i];
	}
	for(long long i=1;2*i<=h;i++){
		long long b=i,o=1;
		while(b>0){
			b-=k[o];
			o++;
		}
		char q1=a[o-1];
		long long p1=k[o-1];
		b=h-i+1,o=1;
		while(b>0){
			b-=k[o];
			o++;
		}
		char q2=a[o-1];
		long long p2=k[o-1];
		if(q1!=q2){
			long long l=min(p1,p2);
			i+=l-1;
			if(i*2==h)sum--;
			sum+=l;
		}
	}
	cout<<sum;
	return 0; 
}
