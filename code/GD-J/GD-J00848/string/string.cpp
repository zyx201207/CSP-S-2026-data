#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10; 
int a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	int i=1,j=n,l=1,r=sum,ans=0;
	while(l<=r&&i!=j){
		if(a[i]>a[j]){
			ans+=a[j]*(c[i]!=c[j]);
			a[i]-=a[j];
			l+=a[j];
			r-=a[j];
			j--;
		}
		else if(a[i]<a[j]){
			ans+=a[i]*(c[i]!=c[j]);
			a[j]-=a[i];
			l+=a[i];
			r-=a[i];
			i++;
		}
		else if(a[i]==a[j]){
			ans+=a[i]*(c[i]!=c[j]);
			l+=a[i];
			r-=a[i];
			i++;
			j--;
		}
	}
	cout<<ans<<endl;
	return 0; 
} 
