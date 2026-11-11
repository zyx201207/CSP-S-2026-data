#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=200010;
ll n,ans=0,i=1,j;
ll a[N];
char b[N],s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	j=n;
	for(int k=1;k<=n;k++) cin>>a[k]>>b[k];
	while(i<j){
		if(a[i]<a[j]){
			if(b[i]!=b[j]) ans+=a[i];
			a[j]=a[j]-a[i];
			i++;
		}else if(a[i]>a[j]){
			if(b[i]!=b[j]) ans+=a[j];
			a[i]=a[i]-a[j];
			j--;
		}else{
			if(b[i]!=b[j]) ans+=a[i];
			i++;
			j--;
		}
	}
	cout<<ans;
	return 0;
	//Trick||Treat!
}
