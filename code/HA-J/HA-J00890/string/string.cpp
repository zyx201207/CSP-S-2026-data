#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,k=0;
	cin>>n;
	int a[n];
	char c[n];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int i=1,j=n;
	while(i!=j){
		if(a[i]==0){
			i++;
			continue;
		}
		if(a[j]==0){
			j--;
			continue;
		}
		if(c[i]!=c[j]){
			k++;
		}
		a[i]--;
		a[j]--;
	}
	cout<<k;
	return 0;
}
