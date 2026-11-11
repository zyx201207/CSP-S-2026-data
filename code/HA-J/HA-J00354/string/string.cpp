#include <bits/stdc++.h>
using namespace std;
int duo[100000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,xt=0;
	cin >> n;
	int a[100000];
	string b;
	long long sum=0,ans=0;
	for(int i=1;i<=n;i++){
		cin >> a[i] >>b[i];
		sum+=a[i];
		char zm=b[1],xt1=b[1];
		if(b[i]==zm){
			ans+=a[i];
		}
		else{
			duo[i-1]=ans;
			ans=0;
			ans+=a[i];
			zm=b[i];
		}
		if(b[i]==xt1){
			xt=1;
		}
		else{
			continue;
		}
	}
	if(xt==1){
		cout << 0;
		return 0;
	}
	long long zd=0;
	for(int i=1;i<=n;i++){
		if(zd<=duo[i]){
			zd=duo[i];
		}
	}
	if(sum%2==0){
		cout << sum-zd;
		return 0;
	}
	return 0;
}
