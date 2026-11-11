#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,a[20005],m,sum=0,ma=0,maxx=0;
	cin>>n>>m;for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	sum=a[0];
	for(int i=1;i<m;i++){
		cout<<sum<<"&"<<a[i]<<"="<<(sum&a[i])<<"\n";
		sum=(sum&a[i]);
	}
	cout<<sum;
	return 0;
}