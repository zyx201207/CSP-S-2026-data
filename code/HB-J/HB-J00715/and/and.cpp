#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,maxt=0;
bool flag=1;
int ct[200005];
int a[200005];
bool book[200005];
string s[200005];
void rjz(int x){
	cnt++;
	s[cnt]=" ";
	while(x!=0){
		bool t=x%2;
		if(t) s[cnt]+='1';
		else{
			s[cnt]+='0';
			flag=0;
		}
		ct[cnt]++;
		x/=2;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxt=max(maxt,a[i]);
		rjz(a[i]);
	}
	if(m==1){
		cout<<maxt;
		return 0;
	}
	if(m==2){
		int ans=0;
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(flag==1){
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
		return 0;
	}
	return 0;
}
