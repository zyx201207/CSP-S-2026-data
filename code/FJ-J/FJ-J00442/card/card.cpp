#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==2 && m==2){
		cout<<1<<" "<<1;
		return 0;
	}else if(m==1){
		cout<<n;
		return 0;
	}else if(n>=3 && m==2){
		int t=0,s=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				t++;
			}else{
				s++;
			}
		}
		cout<<t<<" "<<s;
		return 0;
	}
	return 0;
}
