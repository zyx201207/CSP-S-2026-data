#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000005];
bool flag1=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) flag1=0;
	}
	if(flag1==1){
		long long i1=0,i2=1;
		while(i1<(n-1)*n/2){
			i1+=i2;
			if(i1>=m) break;
			i2++;
		}
		//cout<<i1<<" "<<i2<<endl;
		//cout<<(1+i2)*i2/2<<endl;
		if(m==(1+i2)*i2/2) cout<<i2+1;
		else cout<<i2;
	}else cout<<m/2;
	return 0;
}
