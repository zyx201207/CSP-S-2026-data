#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freoprn("and.out","w",strout);
	int n,a[200001],m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,cmp);
	long long k=a[0];
	for(int i=1;i<n;i++){
		if(m==0) break;
		if((k/a[i])%2!=0||abs(k-a[i])!=1){
			k&=a[i];
			m--;
		}
	}
	if(k==0) cout<<a[1];
	else cout<<k;
	return 0;
}
