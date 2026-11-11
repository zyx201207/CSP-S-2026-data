#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen ("card.in","r",stdin);
	freopen ("card.out"."w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n],b[n]={0};
	for(long long i=0;i<n;i++){
		cin>>a[i];
		for(long long j=i-1;j>=0;j--){
			if(i!=0&&a[i]==a[j]){
				for(long long w=0;w<j){
					a[w]==a[j+w];
					b[w]+=1;
				}
			}
		}
	}
	for(long long q=0;q<n;q++)
		cout<<b[q];
	return 0;
}
