#include<bits/stdc++.h> 
#define ll long long
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int aa[N][32];
void fj(int x,int t){
	for(int i=31;i>=0;i--){
		if(x==0){
			break;
		}
		aa[t]=0;
		
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		fj(a[i],i);
	}
	
	return 0;
}
