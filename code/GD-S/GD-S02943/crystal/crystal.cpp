#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+6;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	int n=0;
	ll m=0;
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	int d=a[2]-a[1];
	
	int k=0;
	for(int i=1;i<=n;i++){
		k+=d;
		if(m>=k){
			for(int j=1;j<=i;j++){
				a[j]+=d;
				m-=d;
			}
		}
		else break;
	}
	int cnt=0;
	for(int i=2;i<=n;i++)if(a[i]==a[1])cnt++;
	printf("%d",cnt+1);
	fclose(stdin);fclose(stdout);
	return 0;
}

