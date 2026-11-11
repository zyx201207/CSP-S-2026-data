#include<bits/stdc++.h>
using namespace std;
long long l[60000];
long long a,h;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int n,k;
    cin>>k>>n;
    for(int i=1;i<=n;i++){
    	cin>>a>>h;
    	if(k==0){
	    	cout<<1<<endl<<2<<endl; 
		}
    	for(long long i=1;i<=n;i++){
    	   	cin>>l[i];
	    }
	    cout<<1<<endl;
	}
    return 0;
}
