#include<bits/stdc++.h>
using namespace std;
int a[5010],b[5010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long cnt=0;
	for(int i=1;i<=n;i++){
		long long o=n-i+1;
		for(int j=1;j<=n-i+1;j++){
			b[j]=a[j+(n-(n-i+1))];
			for(int k=1;k<j;k++){
				if(b[k]==b[j]){
					b[k]=b[j];
					j=k;
					o-=j;
					o+=k;
					break;
				}
			}
			if(j==o){
				break;
			}
		}
		for(int j=1;j<=o;j++){
			if(b[j]==m){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
} 
