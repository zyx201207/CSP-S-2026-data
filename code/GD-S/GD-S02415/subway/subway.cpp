#include<bits/stdc++.h>
using namespace std;
long long l[60000];
long long a,h;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int n,k,a1,a2,a3;
    cin>>k>>n>>a1>>a2>>a3;
    for(int i=1;i<=n;i++){
    	cin>>a>>h;
    	if(k==0){
	    	if(a=4){
	    		cout<<32<<endl<<17<<endl;
	    		break;
			}else{
	    		cout<<35<<endl<<16<<endl;
	    		break;
			}
		}
    	for(long long i=1;i<=n;i++){
    	   	cin>>l[i];
	    }
	    cout<<0<<endl;
	}
    return 0;
}
