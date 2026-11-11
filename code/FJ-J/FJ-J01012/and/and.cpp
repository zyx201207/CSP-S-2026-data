#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,mn,m;
	cin >> n >> m;
    if(m==1){
    	for(int i=1;i,=n;i++){
	        int a;
		    cin >> a;
	    	mn=max(a,mn);	
	    }
	}
	cout << mn;
	return 0;
}
