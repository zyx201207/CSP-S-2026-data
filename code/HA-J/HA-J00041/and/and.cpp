#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int n,m,a[N],t[33];
bool check(int a){
	int num=0;
	while(a){
		if(a%2 == 1) num++;
		a/=2;
	}
	if(num != m) return false;
	else return true;
}
void deal1(){
	int p=1<<n;
	int maxx=-1;
	for(int i=0;i<=p-1;i++){
		if(check(i) == false) continue;
		int t=i;
		int j=0;
		int ans=0;
		int c=0;
		while(t){
			if(t%2 == 1 && c == 0){
				ans=a[j];
				c++;
				//cout<<ans<<' ';
				//cout<<j<<' ';
			}
			if(t%2 == 1 && c != 0){
				ans=ans&a[j];
				//cout<<ans<<' ';
				//cout<<j<<' ';
				c++;
			}
			t/=2;
			j++;
		}
		//cout<<ans<<'\n';
		maxx=max(maxx,ans);
	}
	cout<<maxx;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	int maxx=-1;
	bool flag1=false;
	bool flag2=false;
	bool flag3=false;
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(n <= 20){
		deal1();
		return 0;
	}
	if(m == 1){
		cout<<maxx;
		return 0;
	}
	if(m == 2){
		int maxx=-1;
		int ans=0;
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				ans=a[i]&a[j];
				maxx=max(ans,maxx);
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m == n){
		int ans=a[0];
		
		for(int i=1;i<n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	//if(m == n-1){
		
	//}
	return 0;
}
