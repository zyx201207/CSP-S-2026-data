#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],sum;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
    if(n==1)cout<<0;
	else{
		for(int i=1;i<=n;i++){
			if(a[i]==a[n-i+1]){
				if(c[i]==c[n-i+1])cout<<0;
				else sum+=a[i];
			}
		}
		cout<<sum;
    }
	return 0;
}











