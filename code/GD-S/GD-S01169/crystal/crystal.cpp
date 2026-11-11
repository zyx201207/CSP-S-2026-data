#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
unsigned long long n,m,b[N],Ans[N];
int a[N];
void solveAll(){
	int mx=0;
	for(int i=1;i<n;i++){
		b[i]=abs(a[i+1]-a[i]);
	}
	for(int i=1;i<n;i++){
		bool flag=1;
		for(int j=1;j<n-i;j++){
			Ans[j]=Ans[j]+b[j+i]*(i+1);
			if(m>Ans[j]){
				mx=i+1;
				flag=0;
			}
		}
		if(flag=0)break;
	}
	cout<<mx+1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	solveAll();
	return 0;
}
