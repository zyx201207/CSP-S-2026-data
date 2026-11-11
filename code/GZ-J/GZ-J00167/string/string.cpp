//GZ-J00167 贵阳市第一中学 谢云龙 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll sum[N];
int oii[N],c[N],a[N],ca[N],b[N],cb[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	int n;
	char ch;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>oii[i]>>ch;
		sum[i]=sum[i-1]+1ll*oii[i];
		c[i]=ch-'A'+1;
	} 
	ll mid=(sum[n]+1)/2;
	int x=1;
	for(int i=1;i<=n;i++){
		if(sum[i]>=mid){
			x=i;
			break;
		}
	}
	int i=1,j=n;
	ll ok=0,ans=0;
	while(i<j){
		if(sum[i]-ok<sum[n]-sum[j-1]-ok){
			if(c[i]!=c[j]){
				ans+=sum[i]-ok;
			}
			ok=sum[i];
			i++;
		}
		else{
			if(c[j]!=c[i]){
				ans+=sum[n]-sum[j-1]-ok;
			}	
			ok=sum[n]-sum[j-1];
			j--;	
		}
	}

	cout<<ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
