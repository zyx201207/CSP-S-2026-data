#include<bits/stdc++.h>
using namespace std;
int n,m;
string a[200005];
long long num[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;

	for(int i=0;i<n;i++){
		cin >> num[i];
	}
	for(int i=0;i<n;i++){
		long long x=num[i];
		while(x!=0){
			a[i]=a[i]+(char)(num[i]%2);
			x=x/2;
		}
	}
	
	return 0;
} 
