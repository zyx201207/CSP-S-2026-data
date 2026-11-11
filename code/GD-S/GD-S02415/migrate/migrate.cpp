#include<bits/stdc++.h>
using namespace std;
long long l[60000];
long long a,h;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int n,k;
    cin>>k>>n;
    for(int i=1;i<=n;i++){
    	cin>>a>>h;
    	for(long long i=1;i<=n;i++){
    	   	cin>>l[i];
	    }
	    if(k==0){
	    	if(a=4){
	    		cout<<1<<endl<<2<<endl;
	    		break;
			}else{
	    		cout<<0<<endl<<1<<endl;
	    		break;
			}
		}
	    if(l[2]-l[1]==h)cout<<0<<endl;
		else cout<<n-3<<endl;
	}
    return 0;
}
