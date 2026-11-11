#include<bits/stdc++.h>
using namespace std;
int k,n,i,j,l,m;
long long ans;
struct tt{
	int k;
	char c;
}a[1000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.ans","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i].k>>a[i].c;
	}
	i=1;
	j=n;
	while(1){
		if(j==i||j<i)break;
		if(a[i].k>a[j].k&&a[i].c!=a[j].c){
			ans+=a[j].k;
			a[i].k-=a[j].k;
			j--;
			continue;
		}
		if(a[i].k<a[j].k&&a[i].c!=a[j].c){
			ans+=a[i].k;
			a[j].k-=a[i].k;
			i++;
			continue;
		}
		if(a[i].k<a[j].k&&a[i].c==a[j].c){
			a[j].k-=a[i].k;
			i++;
			continue;
		}
		if(a[i].k>a[j].k&&a[i].c==a[j].c){
			a[i].k-=a[j].k;
			j--;
			continue;
		}
		if(a[i].k==a[j].k&&a[i].c==a[j].c){
			i++;
			j--;
			continue;
		}
		if(a[i].k==a[j].k&&a[i].c!=a[j].c){
			ans+=a[i].k;
			
			i++;
			j--;
			continue;
		}
	}
	cout<<ans;
	return 0;
}
