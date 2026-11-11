#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int ce,s,f=0,l=0,cnt=0;
	long long n,d;
	cin>>ce>>s;
	long long x,m[s];
	for(int e=0;e<s;e++){
	 cnt=0;
		cin>>n>>d;
		long long a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		long long b[n];
		while(l<n){
			f=0;
			x=a[0+l];
			f=f+l;
				while(x!=a[n-1]){
					for(int i=n-1;i>x-1;i--){
						if(abs(i-x)<=d){
							x=a[i];
							f++;
							if(x==a[n-1]){
							break;
						}
						}
					}
				}
			b[l]=f;
			l++; 
		}
		l=b[0];
		for(int j=0;j<n;j++){
			if(b[j]<l){
				l=b[j];
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(b[i]==b[j] && b[i]==l){
					cnt++;
				} 
			}
		}
		m[e]=cnt;
	}
	for(int j=0;j<s;j++){
		cout<<m[j];
	}
	return 0;
} 
