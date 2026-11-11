#include<bits/stdc++.h>
using namespace std;
long long a,b,c[500005],d[500005],e[500005],l,r;
bool check(int x){
	long long s=999999999999999;
	for(int i=1;i<=a-x+1;i++){
		s=min(s,c[i+x-1]*x-d[i+x-1]+d[i-1]);
	}//cout<<(s>=b);
	return s<=b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio();cin.tie(0);cout.tie(0);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
	}sort(c+1,c+a+1);
	for(int i=1;i<=a;i++){
		d[i]=d[i-1]+c[i];
	}r=a;
	while(l<r){
		long long mid=(l+r+1)/2;
		if(check(mid))l=mid;
		else r=mid-1;
	}cout<<l;
} 
