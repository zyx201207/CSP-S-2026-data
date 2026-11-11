#include<bits/stdc++.h>
using namespace std;
long long n,m,s=1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long a[n];
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=0;i<n;i++){
		if(a[i]<a[i+1]){
			m--;
			a[i]++;
		}if(a[i]==a[i+1]){
			s++;
		}
		if(m==0){
			break;
		}
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
