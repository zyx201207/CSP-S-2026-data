#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,cnt=1,x=0,w;
	cin>>n>>m;
	long long a[n+5];
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(long long i=n-1;i>0;i--){
		w=m;
		for(long long j=i-1;j>=0;j--){
			if(w<a[i]-a[j])break;
			cnt++;
			w-=a[i]-a[j];
		}
		x=max(x,cnt);
		cnt=1;
	}
	cout<<x<<endl;
	return 0;
}
