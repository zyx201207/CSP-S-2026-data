#include<bits/stdc++.h>
using namespace std;
long long a[1000005],maxn;
int n,m;
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1){	
		cout<<a[n];
		return 0; 
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int x=a[i]&a[j];
				if(x>maxn)maxn=x;
			}
		}
		cout<<maxn;
		return 0;
	}
	return 0;
}
