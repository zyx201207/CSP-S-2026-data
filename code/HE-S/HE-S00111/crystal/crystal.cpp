#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[500010];
int c[500010],p[500010];
int ans=0;
int main(){
	foropen("crystal.in"."w"stdin);
	foropen("crystal.out"."r"stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		p[i]=a[i]-a[i-1];
		cout<<p[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		cout<<i<<endl;
		int cost=0,cnt=0;
		for(int j=i;j>=1;j--){
		   cost+=p[i-1]-p[j-2];
		   cout<<cost<<" "<<j-2<<" "<<cost<<endl;
		   if(cost>m)break;
		   cnt++;
    }
	}
	p[0]=0;
	p[1]=0;
	cout<<endl;
	for(int i=2;i=n;i++){
	
	}
	ans=max(cnt,ans);
	cout<<endl<<ans<<endl;
cout<<ans<<endl;
return 0;
}
