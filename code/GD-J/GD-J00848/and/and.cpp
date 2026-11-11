#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10; 
int a[N];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(m==1){
		cout<<a[1]<<endl;
		return 0;
	} 
	if(m==n){
		for(int i=1;i<=n;i++){
			a[1]&=a[i];
		}
		cout<<a[1]<<endl;
		return 0;
	}
	cout<<a[m]<<endl;
	return 0; 
} 
