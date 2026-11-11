#include<bits/stdc++.h>
using namespace std;
struct pp{
	long long num;
	long long yi;
}a[200005];
long long n,m;
long long ans=1;
void zhuan(pp x){
	long long temp=x.num;
	while(temp!=0){
		if(temp%2==1){
			x.yi++;
		}
		temp/=2;
	}
}
bool cmp(pp x,pp y){
	return x.yi>y.yi;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].num;
		zhuan(a[i]);
	}
	sort(a,a+1+n,cmp);
	for(int i=1;i<=m;i++){
		ans=ans & a[i].num;
	}
	cout<<ans;
	
	
	
	
	
	return 0;
}
