//T2 string
#include<bits/stdc++.h>
using namespace std;
int n;
int a[200050];
char c[200050];
long long ans;
int l,r;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d %c",a+i,c+i);
	l=1;r=n;
	while(l<r){
		if(a[l]<=a[r]){
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			a[r]-=a[l];
			l++;
			if(a[r]==0)r--;
		}else{
			if(c[l]!=c[r]){
				ans+=a[r];
			}
			a[l]-=a[r];
			r--;
		}
	}
	cout<<ans;
	return 0;
}
