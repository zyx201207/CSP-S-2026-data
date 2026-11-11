#include<bits/stdc++.h>
using namespace std;

int a[100005];
int ans[100005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,b=0;
	cin>>n>>m;
	int num=0,cnt=0;
	num=n/2+1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ans[i]=abs(a[i]-a[num]);
		cnt+=ans[i];
		b++;
		if(cnt==m){
			break;
		} 
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[num]){
			b++;
		}
	}
	cout<<b;
	return 0;
}
