#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000008;
int a[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,l=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		if(a[i]!=a[i++]){
			a[i]++;
		}
		if(a[i]==a[i++]){
			l++;
			i++;
		}
	}
	cout<<l+1<<endl;
	return 0;
} 
