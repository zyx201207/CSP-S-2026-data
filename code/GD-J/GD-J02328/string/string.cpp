#include <iostream>
using namespace std;
const int MAXN=2e5+10;
int n,a[MAXN],len,l,r,ans;
char c[MAXN];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	for(int i=1;i<=n;i++){
		l+=a[i];
		while(a[i]>a[r]){
			if(c[i]!=c[r]) ans+=a[r];
			a[i]-=a[r];
			r++;
		}
		if(c[i]!=c[r]) ans+=a[i];
		a[r]-=a[i];
		a[i]=0;//×óÓÒµÖÏû
	}
	cout<<ans;
	return 0;
}
