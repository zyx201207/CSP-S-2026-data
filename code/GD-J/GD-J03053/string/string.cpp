#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],ans=0;
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(c[i]==c[i-1])  a[i-1]+=a[i],i--,n--;
	}
	int x=a[1],y=a[n];
	//cout<<n<<'\n';
	//for(int i=1;i<=n;i++)  cout<<c[i]<<' '<<a[i]<<'\n';
	for(int i=1,j=n;i<j;){
		if(c[i]!=c[j])  ans+=min(x,y);
		if(x>y)  x-=y,j--,y=a[j];
		else if(x<y)  y-=x,i++,x=a[i];
		else  i++,j--,x=a[i],y=a[j];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
