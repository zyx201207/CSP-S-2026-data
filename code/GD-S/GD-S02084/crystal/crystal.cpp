#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,b[500010],t=0,a[500010];
int main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++) b[i]=a[i+1]-a[i-1];
	while(m){
		if(a[2]-a[1]<m){
			t++;
			m-=(a[2]-a[1]);
			a[1]=max(a[1],a[2]);
			int t=
			a[1]*=2;
			a[2]=INT_MAX;
			sort(a+1,a+1+n);
			n--;
//			for(int i=1;i<n;i++){
//				b[i]=a[i+1]-a[i];
//			}
			
		} else {
			break;
		}
	}
	cout<<t;
	return 0;
}
