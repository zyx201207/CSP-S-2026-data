#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5;
ll n,cnt=0;
ll a[N+5];
string c[N+5],str[N],str1[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i]>>c[i];
	for(int i=0;i<n;i++){
		for(int j=1;j<=a[i];j++){
			str[N]+=c[i];
			cnt++;
		}
	}
	ll cnt1=cnt;
	for(int i=0;i<cnt;i++){
		str1[i]=str[cnt1-1];
		cnt1--;
		cout<<str1[i];
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
