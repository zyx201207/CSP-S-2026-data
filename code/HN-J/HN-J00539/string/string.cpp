#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+7;
long long a[MAXN];
char c[MAXN];
long long ans,sum;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	if(sum%2==0) ans=sum/2;
	else ans=(sum-1)/2;
	int i=1,j=n;
	while(i<=n&&j>=1&&i<=j){
		if(i==j){
			if(a[i]%2==0) ans-=a[i]/2;
			else ans-=(a[i]-1)/2;
			break;
		}
		if(c[i]!=c[j]){
			if(a[i]>=a[j]){
				a[i]-=a[j];
				j--;
			}
			else{
				a[j]-=a[i];
				i++;
			}
		}
		else{
			if(a[i]>=a[j]){
				ans-=a[j];
				a[i]-=a[j];
				j--;
			}
			else{
				ans-=a[i];
				a[j]-=a[i];
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
3
2 a
2 b
1 c
*/
