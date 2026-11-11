#include<bits/stdc++.h>
using namespace std;

long long n,k,ans;
int num;
char word;
char a[1000000005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num>>word;
		for(int j=1;j<=num;j++){
			a[k+j]=word;
		}
		k+=num;
	}
	for(long long i=1;i<=k/2;i++){
		if(a[i]!=a[k-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
