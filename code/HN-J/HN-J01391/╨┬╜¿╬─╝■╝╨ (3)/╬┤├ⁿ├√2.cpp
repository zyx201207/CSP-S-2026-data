#include<bits/stdc++.h>
using namespace std;//Trick||Treat! travel
int sb(long long a,long long b){
	return a&b;
}
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int s=0;
	int l,r;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			s=max(s,sb(a[i],a[j]));
			if(s==sb(a[i],a[j])){
				l=a[i];
				r=a[j];
			}
		}
	}

	if(m==3){
		int y=s;
		s=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=l&&a[i]!=r){
				s=max(s,sb(a[i],y));
			}
		}
	}
	cout<<s;
	return 0;
} 
