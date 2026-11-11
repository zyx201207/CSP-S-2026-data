#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0,sum=n;
	while(n!=0){
	for(int i=1;i<=n-1;i++){
		cnt+=a[n]-a[i];
	}
	if(cnt>m){
		n--;
		continue;
		}else{
			break;
		}
	}
	cout<<sum-1;
	return 0;
} 
