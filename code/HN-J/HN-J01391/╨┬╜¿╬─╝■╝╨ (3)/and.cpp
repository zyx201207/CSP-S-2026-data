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
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			s=max(s,sb(a[i],a[j]));
		}
	}
	cout<<s;
	return 0;
} 
