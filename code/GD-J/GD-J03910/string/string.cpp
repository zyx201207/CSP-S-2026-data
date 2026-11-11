#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],ans;
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int a1=0,a2=0,l=0,r=n+1;
	char c1,c2;
	while(l<=n && r>=1){
		if(a1==0){
			l++;
			a1=a[l];
			c1=c[l];
		}
		if(a2==0){
			r--;
			a2=a[r];
			c2=c[r];
		}
		if(c1==c2){
			if(a1<=a2){
				a2-=a1;
				a1=0;
			}
			else{
				a1-=a2;
				a2=0;
			}
		}
		else if(a1<=a2){
			ans+=a1;
			a2-=a1;
			a1=0;
		}
		else{
			ans+=a2;
			a1-=a2;
			a2=0;
		}
	}
	cout<<ans/2;
	return 0;
}
