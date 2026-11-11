#include<bits/stdc++.h>
using namespace std;
int m=1,n,a[200010];
long long s;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	while(m!=n){
		if(c[m]!=c[n]){
			if(a[m]>=a[n]){
				a[m]-=a[n];
				s+=a[n];
				n--;
			}else{
				a[n]-=a[m];
				s+=a[m];
				m++;
			}
		}else{
			if(a[m]>=a[n]){
				a[m]-=a[n];
				n--;
			}else{
				a[n]-=a[m];
				m++;
			}
		}
	}
	cout<<s;
	return 0;
}
