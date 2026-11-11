#include<bits/stdc++.h>
using namespace std;
long long n,a[10005],ma,k,ma2;
int main(){
	freopen("and3.in","r",stdin);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	ma2=0;
	for(int i=1;i<=n;i++){
		if(a[i]==ma){
			continue;
		}
		ma2=max(ma2,a[i]);
	}
	cout<<(ma&mb);
	return 0;
}
