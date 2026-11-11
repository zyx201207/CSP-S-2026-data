#include<bits/stdc++.h>
using namespace std;
long long p[500005];
long long o[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long a,b;
	cin>>a>>b;
	int ee=0;
	for(int i=1;i<=a;i++){
		cin>>p[i];
	}
	sort(p+1,p+1+a);
	for(int i=2;i<=a;i++){
		o[i]=p[i]-p[i-1];
		if(i!=2) {
			if(o[i]!=o[i-1]) {
				ee=1;
			}
		}
	}
	if(ee==0){
		long long ans=1;
		long long e=1;
		for(int i=2;i<=a;i++){
			if(e>b){
				break;
			}
			e+=i*o[i];
			ans++;
		}
		cout<<ans;
		return 0;
	}
	long long ans=0;
	long long anns=0;
	int e=0;
	for(int i=2;i<=a;i++){
		anns=1;
		e=0;
		for(int j=i;j>=2;j--){
			e+=o[j]*(j-1);
			if(e>b) {
				break;
			}
			anns++;
		}
		ans=max(ans,anns);
	}
	cout<<ans;
	return 0;
} 
//Oct31==Dec25?
