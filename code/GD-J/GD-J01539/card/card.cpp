#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],b,c;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			b++;
		}if(a[i]==2){
			c++;
		}
	}
	if(m==2){
		if(a[n]==1){
			cout<<n<<" ";
			if(b-1>0){
				cout<<1;
			}else cout<<n;
		}else{
			if(c-1>0){
				cout<<1<<" "<<n;
			}else cout<<n<<" "<<n;
		}
	}
	return 0;
}
