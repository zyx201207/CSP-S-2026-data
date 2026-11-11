#include<bits/stdc++.h>
using namespace std;
const long long N=500;
long long n,a[N],sum;
string s,c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s=s+c[i];
		}
		sum+=a[i];
	}
	if(n==1){
		cout<<0;
	}else if(n==2){
		if(a[1]>a[2]&&c[1]!=c[2]) cout<<a[2];
		else if(a[2]>a[1]&&c[1]!=c[2]) cout<<a[1];
		else cout<<0;
	}else if(n<=10){
		int cnt;
		for(int i=2;i<=n;i++){
			if(c[i]==c[i-1]) cnt++;
		}if(cnt==n) cout<<0;
	}
	return 0;
}
