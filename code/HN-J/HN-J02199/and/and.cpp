#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	int n,m=0,a=0;cin>>n;
	if(n%2==1){
		n--;
		m=1;
	}
	while(n>0){
		a++;
		if(pow(2,a)>n) n-=pow(2,a-1),a=0,cout<<1;
		else if(pow(2,a)==n){
			n-=pow(2,a);
			cout<<1;
			for(int i=1;i<a;i++){
				cout<<0;
			}
			break;
		}
	}
	if(m==1) cout<<1;
	return 0;
}
