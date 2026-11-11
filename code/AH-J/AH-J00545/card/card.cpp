#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[100000005];
int main(){
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		if(a[i]==a[i+1]){
			a[i]={0};
			a[i]==a[i]+1;
			cout<<a[i]<<"\n";
		}
	}
	return 0;
}
