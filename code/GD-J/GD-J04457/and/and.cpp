#include<bits/stdc++.h>
using namespace std;
long long n,m,s[200001];
int main(){
	freopen("and.in"."r",stdin);
	freopen("and.out"."w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	long long maxx=0;
	for(int i=1;i<=n;i++){
		if(s[i]>maxx){
			maxx=s[i];
		}
	}
	cout<<maxx;
	return 0;
}
