#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N],ans,n;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	int l=1,r=n,ls1=a[l],ls2=a[r];
	while(l<=r){
		int temp=min(ls1,ls2);
		if(c[l]!=c[r])
			ans+=temp;
		ls1-=temp,ls2-=temp;
		if(ls1==0)
			ls1=a[++l];
		if(ls2==0)
			ls2=a[--r];
	}
	cout<<ans<<endl; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
