#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	freopen("crystal.in","r",std::in);
	freopen("crystal.out","w",std::out);
	int n,m,sum=0;
	cin>>n>>m;
	int a[n+1],b[n+1];
	a[0]=0;
	b[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=n;i>0;i--){
		b[i]-=b[i-1];
	}
	for(int i=2;i<=n;i++){
		sum+=b[i]*(i-1);
		if(sum>m){
			cout<<(i-1);
			break;
		}
	}
	return 0;
}
