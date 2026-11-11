#include<bits/stdc++.h>
using namespace std;
string s[200010];
long long n,t,a[200010],ans=pow(2,31)-1;
bool cmp(long a,long b){
	int a1=0,b1=0;
	while(a){
		if(a%2==1)a1++;
		a/=2;
	}
	while(b){
		if(b%2==1)b1++;
		b/=2;
	}
	return a1>b1;
}
//5 3
//31 3 1 15 7
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
int m;
	cin>>n>>m;	
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
//	for(int i=1;i<=n;i++)cout<<a[i]<<' '; 
	for(int i=1;i<=m;i++){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
} 
