#include <bits/stdc++.h>
using namespace std;
int n,m,a[200010][40],b[200010],ed,ans,pp[40];
bool f[200010];
//void cooo(){
//	for(int i=1,ls; i<=n; i++) {
//		for(int j=10; j>=0; j--) {
//			cout<<a[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<endl;
//}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	ed=n;
	for(int i=30; i>=0; i--) pp[i]=pow(2,i);
	for(int i=1; i<=n; i++) cin>>b[i];
	sort(b+1,b+1+n);
	for(int i=1,ls; i<=n; i++) {
		ls=b[i];
		for(int j=30; j>=0; j--) {
			if(ls>=pp[j]) ls-=pp[j],a[i][j]=1;
		}
	}
	for(int i=30; i>=0; i--) {
		int sum=0;
		for(int j=1; j<=n; j++) {
			if(a[j][i]) sum++;
		}
//		cout<<sum<<" "<<ans<<endl;
		if(sum>=m) {
			ans+=pp[i];
			for(int j=1; j<=n; j++) {
				if(!a[j][i]) for(int k=0;k<=30;k++) a[j][k]=0; 
			}
		}
//		cooo();
	}
	cout<<ans;
	
//	for(int i=0;i<=30;i++) cout<<pp[i]<<" ";
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
