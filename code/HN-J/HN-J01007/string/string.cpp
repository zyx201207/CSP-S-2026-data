#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,ans,a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1,j=n;i<j;){
		if(c[i]!=c[j]){
			int num=min(a[i],a[j]);
			ans+=num;
			a[i]-=num,a[j]-=num;
			if(!a[i])i++;
			if(!a[j])j--;
		}
		else{
			int num=min(a[i],a[j]);
			a[i]-=num,a[j]-=num;
			if(!a[i])i++;
			if(!a[j])j--;
		}
	}
	cout<<ans;
	return 0;
}
//Trick||Treat!
