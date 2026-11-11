/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m;
bool cmp(int a,int b){
	return a>b;
} 
ll a[N],f[N];
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	
	return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m;
ll a[N],f[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		for(int j=m;j>0;--j){
			if(j==1)f[j]=max(f[j],a[i]);
			
			f[j]=max(f[j],f[j-1]&a[i]);
		}
	}
	cout<<f[m];
	return 0;
}
