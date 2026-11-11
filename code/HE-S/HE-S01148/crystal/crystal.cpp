#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int n;
ll m;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			continue;
		}
		if(m==0){
			cnt=cnt+i-1;
			break;
		}
		else if(m<0){
			cnt=cnt+i-2;
			break;
		}
		else{
			int j=1;
			while(j<=i){
				if(a[i]-a[j]<=m){
					ll x=a[i]-a[j];
					a[j]+=x;
					m-=x;
				}
				j++;
			}
		}
	}
	cout<<cnt;      
	return 0;
}



 
