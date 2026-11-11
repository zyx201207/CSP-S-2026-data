#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,m,a[MAXN],s[MAXN],sum=1e9,id,kd;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		if(sum>abs(s[i]-a[i]*i+m)){
			sum=abs(s[i]-a[i]*i+m);
			id=i;
		} 
	}
	kd=id;
	for(int i=1;i<=n;i++){
		if(a[i]==a[id]){
			kd++;
		}
	}
	cout<<kd-1;
	return 0;
}

