#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("crystal","r",stdin);
	freopen("crystal","W",stdout);
	int n,m,cnt=0,f,ans=0;
	cin >>n>>m;
	if(n%2==0){
		f=n/2;
	}
	else {
		f=n/2+1;
	}
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[f]-a[i]<=m){
			cnt++;
			m-=a[f]-a[i];
		}
		if(m==0){
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			ans++;
		}
	}
	cnt+=1;
	cnt+=ans;
	cout <<cnt;
	return 0;
}



















