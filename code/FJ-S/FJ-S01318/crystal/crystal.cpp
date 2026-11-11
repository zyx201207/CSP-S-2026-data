#include<bits/stdc++.h>
using namespace std;

const long long N=1e12;
long long n,m,a[500050],b[500050];
bool check(long long nmid){
	for(int i=0;i<n;i++){
		b[i]=a[i]-nmid;
	}
	long long cnt=0;
	for(int i=0;i<n;i++){
		if(b[i]<=0){
			cnt+=-b[i];
		}
	}
	if(cnt<=m){
		return 1;
	}
	else if(cnt>m){
		return 0;
	}
}

int main(){
//	freopen("crystal.in","w",stdout);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long l=-N,r=N;
	while(l<r){
		long long mid=(l+r+1)/2;
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		if(a[i]==l){
			cnt++;
			continue;
		}
		if(m<0){
			continue;
		}
		if(a[i]<l){
			m-=(l-a[i]);
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
//no;