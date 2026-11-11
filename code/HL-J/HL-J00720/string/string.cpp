#include<bits/stdc++.h>
using namespace std;
long long n1[200005];
long long n,w,ans;
char n2[200005];
string q;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>n1[i];
    	cin>>n2[i];
	}
	for(int i=0;i<n;i++){
    	for(int j=1;j<=n1[i];j++){
	    	q+=n2[i];
	    	w++;
		}
	}
	for(int i=0;i<(w/2)+1;i++){
    	if(((w%2)!=0)&&i==(w/2)+1){
    		break;
		}
		if(q[i]!=q[w-i]){
    		ans++;
		}
	}
	cout<<ans-1;
    return 0;
}