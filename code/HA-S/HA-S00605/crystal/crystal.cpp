#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],bb=0,c,mm,cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++){
		if(b[i]!=b[n])bb=1;
	}
	if(bb==0){
		c=a[2]-a[1];
		while(1){
			cnt++;
			if(mm+cnt*c<=m){
				mm+=(cnt*c);
			}
			else break;
		}
		cout<<cnt;
	}
	else{
		cout<<n-1;
	}	
	return 0;
}
