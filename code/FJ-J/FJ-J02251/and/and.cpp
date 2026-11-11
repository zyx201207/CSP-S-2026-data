#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010];
bool cnt(int a,int b){
	return a<b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cnt);
	cout<<a[m];
	return 0;
} 
