#include <bits/stdc++.h>
using namespace std;
int n,m,sum,c;
int a[100010],b;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
		cin>>n>>m;
	for (int i = 0; i < n; i++){
		cin>>a[i];
		b+=a[i];
	}
sort(a,a+n);
for (int i = 1; i < n; i++){
	if(m<=0) break;
		if(a[i]!=a[i-1]&&m>0&&m>a[i]-a[i-1]){
			m=m-(a[i]-a[i-1]);
			a[i-1]=a[i];
			if(a[0]+m==a[1]) {
				m=m-(a[1]-a[0]);
				a[0]=a[1];
				}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if(a[i]==a[0]) sum++;
	}
	cout<<sum;
}
