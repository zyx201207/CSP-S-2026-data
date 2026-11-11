#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y,z=1,w,k=1,ans,vil;
const long long N=5e5+5;
long long a[N];
long long stl(){
	for(long long i=0;i<=n;i++){
		if(a[i]==a[i+1]){
			++ans;
		}
		if(a[i+1]-a[i]==1){
			++vil;
		}
	}
	if(n==m&&m==ans){
		cout<<m;
		return 0;
	}
	if(vil==n-1){
		for(long long i=1;i<=m;i++){
			long long p=1;
			p+=i;
			if(p>m){
				cout<<p-1;
				return 0;
			}
		}
		return 0;
	}
	for(long long i=0;i<n;i++){
		x=a[i+1];
		y=a[i];
		w+=a[i+1]-a[i];
		if(i+1==n){
			break;
		}
		if(w>=m){
			z=max(z,k);
			k=1;
			w=0;
		}else{
			++k;
		}
		//cout<<k<<" "<<z<<" "<<w<<endl;
	}
	cout<<z;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	stl();
	return 0;
}
