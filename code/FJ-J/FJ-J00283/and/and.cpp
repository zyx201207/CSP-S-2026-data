#include<bits/stdc++.h>
using namespace std;
long long n,i,a[11],an[20];
char c[200005],cn[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	while(cin>>a[i]){
		i++;
	}
	int s=0,p=0;
	while(s!=i){
		for(int j=s;j<i;j++){
			a[j+1]+=(10*(a[j]%2));
			a[j]/=2;
		}
		an[p++]=a[i]/10;
		a[i]=0;
		if(a[s]==0)s++;
	}
	for(int i=0;i<p;i++){
		cout<<an[i];
	}
	return 0;
}
