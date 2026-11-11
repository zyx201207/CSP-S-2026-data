#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int n,a[N];char c[N];ll ans,b[N],cnt,cn,lk,i,j;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i]>>c[i];b[i]=cnt+1;cnt+=a[i];
	}cn=cnt/2;
	for(i=1;i<=n;i++)
		if(b[i]>cn){
			lk=i-1;
			break;
		}
	for(i=1,j=n;i<=lk,j>lk;i++,j--)	
		if(b[j]<=cnt+1-b[i]){
			if(c[i]!=c[j])
				ans+=a[i];
		}else{
			while(b[j]>cnt+1-b[i]){
				if(c[i]!=c[j])
					ans+=a[j];
				j--;a[i]-=a[j];
			}if(c[i]!=c[j])
				ans+=a[i];
		}
	cout<<ans;
	return 0;
}