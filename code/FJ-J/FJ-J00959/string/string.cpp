#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string c[200002],d="";
	long long n,a[200002],b=0,x=0,e,f=1,g=1;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>c[i];
		b+=a[i];
		if(i==0) e=a[i];
		else if(e!=a[i]) f=0;	
	}
	if(f){
		b=n;
		g=a[0];
		for(long long i=0;i<n;i++){
			d+=c[i]; 
		}
	}else{
		for(long long i=0;i<n;i++){
			for(long long j=0;j<a[i];j++){
				d+=c[i];
//				cout<<c[i];
			}
		}
	}
	if(b%2==0){
		for(long long i=0;i<=b/2;i++){
//			cout<<b/2-1-i<<' '<<b/2-1+i<<' '<<d[b/2-1-i]<<' '<<d[b/2-1+i]<<endl;
			if(d[b/2-1-i]!=d[b/2-1+i]) x++;
		}
	}else{
		for(long long i=0;i<=b/2;i++){
//			cout<<b/2-i<<' '<<b/2+i<<' '<<d[b/2-i]<<' '<<d[b/2+i]<<endl;
			if(d[b/2-i]!=d[b/2+i]) x++;
		}
	}
	cout<<x*g;
	return 0;
}

