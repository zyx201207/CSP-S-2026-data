#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
#define ulp(i,a,b) for(int i=a;i<=b;i++)
#define dlp(i,a,b) for(int i=a;i>=b;i--)
int n,m,a[N],ans;
bool flag[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	ulp(i,1,n){
		cin>>a[i];
		flag[i]=true;
	}
	dlp(i,29,0){
		int cnt=0;
		ulp(j,1,n){
			if(!flag[j])continue;
			cnt+=(a[j]>>i&1);
		}
		if(cnt>=m){
			ulp(j,1,n){
				if(!flag[j])continue;
				if(!(a[j]>>i&1))flag[j]=false;
			}
			ans+=(1<<i);
		}
	}
	cout<<ans;
}
