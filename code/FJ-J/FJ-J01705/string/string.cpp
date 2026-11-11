#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+10;

int n;
int a[MAXN];
char c[MAXN];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	
	long long i=1,j=n,l=0,r=0,ans=0,sum;
	while(i<j){
		sum=min(a[i]-l,a[j]-r);
		if(c[i]!=c[j]){
			ans+=sum;
		}
		l+=sum,r+=sum;
		if(l>=a[i]) l-=a[i],i++;
		if(r>=a[j]) r-=a[j],j--;
		//cout<<i<<" "<<l<<" "<<j<<" "<<r<<" "<<sum<<endl;
	}
	cout<<ans;
	return 0;
}
