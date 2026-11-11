#include<bits/stdc++.h> 
using namespace std;

long long n,m;
long long a[500086];
int c[500086];
stack<long long> st;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	long long num=0,best=1,ans=1;
	long long l=1;
	for(int i=2;i<=n;i++){
		num+=a[best]-a[i];
		++l;
		while(num>m){
			num-=(a[best]-a[++best])*(--l);	
		}
		ans=max(ans,l);
	}
	cout<<ans<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
