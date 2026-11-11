#include<bits/stdc++.h>
using namespace std;
const int M=2e5+5;
long long a[M];
char p[M];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long m=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>p[i];
		m+=a[i];
	}
	m/=2;
	int i=1,j=n,c=1,cnt=0;
	while(c<=m){
		if(a[i]==0){
			i++;
			continue;
		}
		if(a[j]==0){
			j--;
			continue;
		}
		if(p[i]!=p[j]){
			cnt++;
		}
		c++;
		a[i]++;
		a[j]--;
	}
	cout<<cnt;
	return 0;
} 
