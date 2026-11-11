#include<bits/stdc++.h>
using namespace std;
char c[300000];
long long a[300000],ans;
int n,q=1,p=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);	
	cin>>n;
	while(n--){
	    cin>>a[q]>>c[q];
	    q++;
	    
	}
	while(p!=q){
		while(a[p]!=0){
		    if(c[p]==c[q]){
				if(a[p]>=a[q]){
					a[p]-=a[q];
					q--;
				}
				else{
					a[q]-=a[p];
					a[p]=0;
				}
			}
			else if(c[p]!=c[q]){
				if(a[p]>=a[q]){
					ans+=a[q];
					a[p]-=a[q];
					q--;
				}
				else{
					ans+=a[p];
					a[q]-=a[p];
					a[p]=0;
				}
			}
		}
		p++;
	}
	cout<<ans;
	return 0;
}
