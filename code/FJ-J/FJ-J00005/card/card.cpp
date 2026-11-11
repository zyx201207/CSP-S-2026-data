#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],sum[200005],len,m;
int main(){
	freopen("card.out","w",stdout);
	freopen("card.in","r",stdin);

	cin >> n    >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		sum[i]=sum[i-1]+1;
		len++;
		if(a[i-1]!=a[i]){
			if(len%2==1){
				cout << sum[i-len]*len+(len/2+1)*(len/2+1) <<" ";
			}else{
				cout << (len/2)*(len/2) <<" ";
			}
			len=0;
		}
	}
}
