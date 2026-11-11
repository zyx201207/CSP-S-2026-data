#include <bits/stdc++.h>
using namespace std;
long a[200006];
long long ans[200006],num;
long long Find(int x,int y){
	long long p=1;
	for (int i=y;i>=1;i--){
		if (x-a[i]>=0){
			if (ans[i]!=0){
				p*=ans[i];
			}
		}
		else{
			return p;
		}
	}
	return p;
}
int c,t;
int main()
{
	freopen ("migrate.in","r",stdin);
	freopen ("migrate.out","w",stdout);
	cin>>c>>t;
	while (t--){
		long long n,d;
		num=0;
		cin>>n>>d;
		for (int i=1;i<=n;i++){
			cin>>a[i];
		}
		ans[1]=0;
		for (int i=1;i<=n;i++){
			ans[i]=Find(d,i);
		}
		for (int i=1;i<=n;i++){
			num+=ans[i];
		}
		cout<<num<<endl;
	}
	return 0;
}
