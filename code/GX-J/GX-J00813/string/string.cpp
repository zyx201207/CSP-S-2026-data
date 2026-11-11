#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int n,ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n==1){
		cout<<0;
		return 0;
		}
    for(int i=0;i<n;i++){
	    cin>>a[i];
	    if(n==2){
		ans=min(a[0],a[1]);
		cout<<ans;
		break;
		}else{
		cout<<n-1;
		break;
		}
	}
		
    return 0;
}

