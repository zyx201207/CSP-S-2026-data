#include<bits/stdc++.h>
using namespace std;
long long a[500100];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long s=0,ma=0;
	for(int i=1;i<=n;i++){
		
		int j;
		s=0;
		for(j=i-1;j>=1;j--){
			s+=a[i]-a[j];
			if(s>m){
				break;
			}
		}
		if(i-j>ma)ma=(i-j);
	}
	cout<<ma;
	return 0;
}


