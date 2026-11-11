#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5000005],b[3000005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 1;i <= n;i++){
		if(m == 2){
			if(a[i] == a[n]){//头尾都一样 
				b[a[i]]++;
			}else{
				b[1]++;
				b[2]++;
			}
		}
	}
	cout<<b[1]<<" "<<b[2];
	return 0;
}
