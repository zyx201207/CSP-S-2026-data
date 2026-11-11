#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+10;
LL n,a[N],len,mid,ans;
char ch[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
		len+=a[i];
	}
	int i=1,j=n;
	while(i<j){
		if(ch[i]!=ch[j])
			ans+=min(a[i],a[j]);
		if(a[i]<a[j])
			a[j]-=a[i],i++;
		else if(a[i]==a[j])
			i++,j--;
		else a[i]-=a[j],j--;
	}
	cout<<ans<<endl;
	return 0;
}
