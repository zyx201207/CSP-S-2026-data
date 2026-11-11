#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int s;
bool p=0;
bool oo(long long r,long long l){
	return r>l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	long long h=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=h){
			p=1;
			break;
		}
	}
	if(!p){
		long long u=m/h*2;
		for(int i=n;i>=1;i--){
			if(i*i<=u){
				s=i+1;
				break;
			}
		}
		cout<<s;
		return 0;
	}
	sort(a+1,a+n+1,oo);
	long long f;
	for(int i=1;i<=n;i++){
		f=0;
		int x=1;
		for(int j=i+1;j<=n;j++){
			f+=a[i]-a[j];
			if(f>m) break;
			x++;
		}
		s=max(s,x);
	}
	cout<<s;
	return 0;
} 
