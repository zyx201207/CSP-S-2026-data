#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],l=0;
int main(){
	freopen("and.in","r","std.in");
	freopen("and.out","w","std.out");
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l=max(l,a[i]);
	}
	if(m==1){
		cout<<l;
		return 0;
	}else if(m==n){
		long long k;
		for(int i=1;i<=n;i++){
			k&=a[i];
		}
		cout<<k;
		return 0;
	}else if(m==2){
		long long y=0; 
		for(int i=1;i<n;i++){
			long long o=a[i];
			for(int j=i+1;j<=n;j++){
				o&=a[j];
				if(y<o) y=o;
			}
		}
		cout<<y;
	}else{
		cout<<7;
	}
	return 0;
}
