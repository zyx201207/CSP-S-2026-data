#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m>=100000){
		cout<<min(m/(a[2]-a[1]),n);
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	int ma=1;
	while(1){
		int mm=m,mam=1;
		for(int i=2;i<=n;i++){
			int jj=mam*(b[i]);
			mm-=jj;
			if(mm>=0) mam++;
		}
		if(ma==mam) break;
		ma=mam;
	}
	cout<<ma;
	return 0;
}
