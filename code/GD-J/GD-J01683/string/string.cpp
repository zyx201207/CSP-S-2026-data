#include<bits/stdc++.h>
using namespace std;
int n,a[200007];
char c[200007];
long long l;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	int cntl=1,cntr=n;
	for(long long i=1,j=l;i<=j;){
		int x=min(a[cntl],a[cntr]);
		if(c[cntl]!=c[cntr]){
			ans+=x;
		}
		i+=x;
		j-=x;
		a[cntl]-=x;
		a[cntr]-=x;
		if(a[cntl]==0) cntl++;
		if(a[cntr]==0) cntr--;
	}
	cout<<ans;
	return 0;
}
