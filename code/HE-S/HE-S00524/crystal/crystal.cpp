#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,b=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
    	for(int i=1;i<n;i++){
			b++;
			m=m-i*(a[i+1]-a[i]);
			if(m<0){
				break;
			}
		}
	cout<<b;
	return 0;
}
