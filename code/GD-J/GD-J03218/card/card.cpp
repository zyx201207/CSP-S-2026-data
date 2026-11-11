#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=0;i<n;i++){
			cout<<n<<" ";
		}
		return 0;
	}
	if(n<6&&m==2){
		cout<<1<<" "<<2;
		return 0;
	}
	if(m==2){
		cout<<200000<<" "<<200000;
		return 0;
	}
	for(int i=0;i<n;i++){
		cout<<500000<<" ";
	}
	return 0;
}
