#include<bits/stdc++.h>
using namespace std;
long long a[100010],b[100010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,s=1,p=0;
	cin>>n>>m;
	for(int i=s-1;i<n;i++){
		cin>>a[i];
		for(int j=i-1;j>=0;j--){
			if(a[j]==a[i]){
				a[j]=a[i];
				p=1;
				s=j+2;
			}
		}
		if(p==0){
			s++;
		}
		for(int k=0;k<s;k++){
			b[a[k]]++;
		}
	}
	for(long long i=1;i<=m;i++){
		if(b[i]!=0)cout<<b[i]<<' ';
	}
	return 0;
}
