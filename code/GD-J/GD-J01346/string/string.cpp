#include<bits/stdc++.h>
using namespace std;
int n,a[200010],s,sl=1,sr;
long long st=1,hl,ans=0;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	sr=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		hl+=a[i];
	}
	hl/=2;
	while(st<=hl){
		s=min(a[sl],a[sr]);
		if(c[sl]!=c[sr]){
			ans+=s;
		}
		if(s==a[sl]){
			sl++;
			a[sr]-=s;
		}
		else{
			sr--;
			a[sl]-=s;
		}
		st+=s;
	}
	cout<<ans;
	return 0;
}
