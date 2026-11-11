#include <bits/stdc++.h>
using namespace std;
string sum;
string a[1005];
int nu[10005];
int siz;
int n,m;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>nu[i]>>a[i];

		siz+=nu[i];
		for(i=1;i<=nu[i];i++) sum+=a[i];
	}
	int j=siz,k=1;
	while(j>k){
		if(sum[j]!=sum[k]) m++;
		j--;
		k++;
	}
	cout<<m;
return 0;
}
