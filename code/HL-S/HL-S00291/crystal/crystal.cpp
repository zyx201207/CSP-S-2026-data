#include <bits/stdc++.h>
using namespace std;
long long ma,m1,cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a+0,a+n);
	ma=n/2;
	long long b[n/2];
	for(int i=0;i<n;i++){
		b[i]=ma-a[i];
	}
	for(int i=n;i>0;i--){
		if(b[i]>=0){
			if(m1+b[i]>m){
				break;
			}
			m1+=b[i];
			cnt++;
		}
	}
	if(n%2==0){
		cout<<cnt;
	}else if(n%2!=0){
		cout<<cnt+1;
	}
	return 0;
}
