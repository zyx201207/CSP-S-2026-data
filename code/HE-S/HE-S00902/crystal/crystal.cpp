#include<bits/stdc++.h>
using namespace std;
int a[500005],k=3;
int main(){
int n,m;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==a[i+1]){
			k++;
			break;
		}else{
			if(a[i]<a[i+1]){
				m--;
				a[i]++;
				if(a[i]==a[i+1]){
			k++;
			break;
			}
		if(a[i+1]-a[i]==m){
			a[i]+=m;
			k++;
		}
		}
	}
}
cout<<k;
	return 0;
}
