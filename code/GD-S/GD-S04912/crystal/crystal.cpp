#include<bits/stdc++.h> 
using namespace std;
const int F=5e5+6;
int b[F],a[F];
long long s,d,cnt,ans,n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt+=a[i];
	}
	sort(a+1,a+1+n);
	ans=cnt/n;
	for(int i=1;i<=n;i++){
		
		b[i]=ans-a[i];
		if(b[i]<0) b[i]=2100000000;
	}
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++){
		s+=b[i];
		d++;
		if(s>m){
			d--;
			break;
		}
	}
	cout<<d;
	return 0;
}
