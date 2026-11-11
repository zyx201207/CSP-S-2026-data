#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1919810];
bool cmd(long long a,long long b){
	return a>b;
}
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmd);
	long long ans=a[0];
	for(int i=0;i<m;i++){
		ans&=a[i];
	}
	cout<<ans;
} 
