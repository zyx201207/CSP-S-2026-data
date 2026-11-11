#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt=1;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool b=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]<a[i-1]&&b==1){
			b=0;
		}
	}
	if(b==0) sort(a+1,a+n+1);
	long long q,s;
	for(int i=2;i<=n;i++){
		q=m,s=1;
		for(int j=i-1;j>0;j--){
			if(a[i]-a[j]<=q){
				q=q-a[i]+a[j];
				s++;
			}
			else{
				break;
			}
		}
		cnt=max(s,cnt);
	}
	cout<<cnt;
	return 0;
}
