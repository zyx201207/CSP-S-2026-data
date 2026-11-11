#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n,m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int mi=INT_MAX,ma=INT_MIN;
	int pi,pa;
	int ans=0,cut=0;
	for(int i=1;i<=n;i++){
		while(a[i]!=0){
		    if(a[i]%2==0){
		    	cout<<false;
		    	break;
			}
		    else if(a[i]%2==1){
		    	cout<<true;
		    	break;
			}
			ans++;
		}
	}
	return 0;
}
