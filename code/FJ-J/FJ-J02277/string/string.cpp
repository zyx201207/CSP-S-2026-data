#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],sum,num;
char c[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++){
		if(c[i]!=c[i+1]) break;
		else num++;
	}
	if(num+1==n){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++) sum+=a[i];
	cout<<sum/2;
	return 0;
}
