#include<bits/stdc++.h>
using namespace std;
//ÎÄ¼þ²Ù×÷  long long
int n,m;
long long a[200005];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	long long maxx=0;
	if(m==1){
		sort(a+1,a+1+n,cmp);
		cout<<a[1];
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n-1;++i){
			if(a[i]&a[i+1]>maxx){
				maxx=a[i]&a[i+1];
			}
		}
	}
	else{
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=i+m-1;++j){
				long long b=a[i];
				b&=a[j];
				cout<<b<<" ";
				maxx=max(maxx,b);
			}
		}
	}
	cout<<maxx;
	return 0;
}
