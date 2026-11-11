#include<bits/stdc++.h>
using namespace std;
long long a,c[500005],m=1,n,d;
long long b;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>a>>b;
	for(long long i=1;i<=a;i++){
		cin>>c[i];
	}
	sort(c+1,c+1+a);
	for(long long i=a;i>=1;i--){
		n=1;
		d=b;
		for(long long j=i-1;j>=1;j--){
			if(c[i]-c[j]<=d){
				n++;
				d-=c[i]-c[j];
			}else{
				break;
			}
		}
		m=max(m,n);
		if(m==i){
			break;
		}
	}
	cout<<m;
} 
