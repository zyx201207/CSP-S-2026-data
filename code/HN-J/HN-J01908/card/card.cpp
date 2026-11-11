#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[300005],s[300005]={0},p=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","r",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long t=n+1;
	for(int i=n;i>=1;i--){
		for(int j=i+1;j<=n;j++){
			if(a[j]==a[i]){
				t=j;
				p=1;
			}
		}
		if(p==0){
			t--;
			a[t]=a[i];
		}
		p=0;
		for(int j=t;j<=n;j++){
			s[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
