#include<bits/stdc++.h>
using namespace std;
long long n,m,p,ans;
int a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long t=m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(p<=a[i]) p=a[i];
	}
	for(int i=0;i<n;i++){
		if(t<0){
			p-=1;
			t=m;
			ans=0;
			i=0;
		}	
		if(a[i]<=p){
			t-=p-a[i];
			ans+=1;
		}
	}
	cout<<ans;
	return 0;
}
