#include<bits/stdc++.h>
using namespace std;
string s;
long long l,mid,ans;
int n,a[200005],a1[200005],sum,ch=1;
char ccf[200005],ccf1[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i],&ccf[i]);
		a1[i]=a[i];ccf1[i]=ccf[i];
		l+=a[i];
		sum++;
	}
	mid=(l+1)/2;
	while(ch<sum){
		int temp=min(a[ch],a[sum]);
		if(ccf[ch]!=ccf[sum]){
			ans+=temp;
		}
		a[ch]-=temp;a[sum]-=temp;
		if(0==a[ch])ch++;
		if(0==a[sum])sum--;
	}
	cout<<ans;
	return 0; 
}
