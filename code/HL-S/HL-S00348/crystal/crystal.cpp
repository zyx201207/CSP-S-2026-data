#include<bits/stdc++.h>
using namespace std;
const int N=100090;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long a[N],s[N];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int gh=i+1;
		s[i]=(a[gh]-a[i])*i+s[i-1];
		if(s[i]==m){
			cout<<i+1;
			return 0;
		}
		else if(s[i]>m){
			cout<<i;
			return 0;
		}
	}
	return 0;
}

