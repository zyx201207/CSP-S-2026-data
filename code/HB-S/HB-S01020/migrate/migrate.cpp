#include<bits/stdc++.h>
using namespace std;
const int N=2e6+7;
int c,t,n,d,x,l;
int a[N];
bool check(int x){
	if(x>a[n])return 0;
	for(int i=n;i>0;i--){
		if(a[i]==x)return 1;
	}
	return 0;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		bool flag=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		x=a[2]-a[1];
		for(int i=3;i<=n;i++){
			if(a[i]-a[i-1]!=x)flag=1;
			else continue;
		}
		if(c==11||c==12||flag==0){
			int cnt=0;
			for(int i=1;i<d;i++){
				int l=d+i;
				cnt+=(n-l);
			}
			cout<<cnt<<"\n";
		}
		else{
			int cnt=0;
			for(int i=1;i<d;i++){
				l=d+i;
				for(int j=1;j<=n;j++){
					if(check(a[j]+l))cnt++;
					else continue;
				}
			}
			cout<<cnt<<"\n";
		}
	}
	return 0;
}
