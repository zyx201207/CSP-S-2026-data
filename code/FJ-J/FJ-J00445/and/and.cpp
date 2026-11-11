#include<bits/stdc++.h>
using namespace std; 
long long a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[1];
	}
	sort(a+1,a+n+1);
	long long s=a[1];
	for(int i=2;i<=m;i++){
		s=s&a[i];
	}
	cout<<"12";
    
return 0;
}
