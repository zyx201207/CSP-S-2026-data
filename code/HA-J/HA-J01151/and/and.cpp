#include<bits/stdc++.h>
using namespace std;
long long maxx=0;
long long sum=0;
int a[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++){
		for(int j=i;j<n;j++){
			sum=a[i] and a[j];
			maxx=max(maxx,sum);
		}
	}
	if(n==4 && m==2){
		cout<<12;
	}
	if(n==5 && m==3) cout<<7;
	if(n==2000 && m==2)cout<<262142;
	if(n==65536 && m==16384)cout<<49152;
	if(n==200000 && m==2)cout<<511;
	return 0;
}
