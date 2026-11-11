#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int z,x,c[200005];
	cin>>z>>x;
	for(int i=1;i<=z;i++){
	    cin>>c[i];
	}
	sort(c+1,c+z+1);
	cout<<c[z-x+1];
    return 0;
}