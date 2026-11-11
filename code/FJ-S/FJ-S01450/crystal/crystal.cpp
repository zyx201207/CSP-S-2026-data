#include<bits/stdc++.h>
using namespace std;
long long a[10000001];
bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	long long n,m;
	cin>>n>>m;
	long long s2[10000001],x=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		s2[a[i]]++;
	}
	int s=0;
	sort(a,a+n,cmp);
	for(int i=1;i<n;i++){
		s=0;
		for(int j=i-1;j>=0;j--){
			if(a[i]-a[j]>=0){
				s+=a[i]-a[j];
			}else{
				s-=(a[i]-a[j]);
			}
		}
		if(s==m){
			cout<<s2[a[i]]+i;
			return 0;
		}else if(s>m){
			cout<<s2[a[i]]+i-1;
			return 0;
		}
	}
	return 0;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
}
