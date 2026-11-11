#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5; 
long long m,n;
long long a[N];
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin >>m>>n;
    for (int i=1;i<=m;i++){
    	cin >>a[i];
	}
	sort(a+1,a+m+1);
	ans=a[m];
	for (int i=m-1;i>=m-n+1;i--){
		ans =(ans & a[i]);
	}
	cout <<ans;
	return 0;
}

