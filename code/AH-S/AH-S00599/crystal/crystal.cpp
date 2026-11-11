#include<bits/stdc++.h>
using namespace std;
long long a,f[500005],k;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>a>>k;
	for(int i=1;i<=a;i++) cin>>f[i];
	sort(f+1,f+a+1);
	for(int i=1;i<a;i++){
		if(k>=(f[i+1]-f[i])*i){
			k-=(f[i+1]-f[i])*i;
		}else{
			cout<<i;
			return 0;
		}
	}
}
