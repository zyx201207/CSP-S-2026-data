#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],x=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	x=a[n];
    if(m!=1){
    	if(m>2){
    		for(int i=n-1;i>=n-m+1;i--)x&=a[i];
		}else x&=a[n-1];
	}
	if(x==0&&m==2)cout<<a[n-1];
	else cout<<x;
	return 0;
} 
