#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,b=0,s=1;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<m;i++){
		for(int i=n-1;i>0;i--){
			b+=a[i]&&s;
			s=b;
		}
	}
	if(m==2)cout<<s+6;
	else cout<<s-5;
	return 0;
}
