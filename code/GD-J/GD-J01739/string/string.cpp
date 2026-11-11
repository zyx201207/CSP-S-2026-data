#include<bits/stdc++.h>
using namespace std;
const long long N = 2e6+5;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

    long long n,l,dig=0,cnt=0;
    char a,L[N];
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>l>>a;
        for(int j=0;j<l;j++){
        	L[dig]=a;
        	++dig;
		}
	} --dig;
		for(int i=0;i<dig/2;i++){ //mid=dig/2
			if(L[i]!=L[dig-i]) {
				++cnt;
				
			}
		}
		cout<<cnt;
		return 0;
}
 
