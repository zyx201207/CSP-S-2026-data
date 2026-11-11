#include<bits/stdc++.h>
using namespace std;
int ll[200000];
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n,y=0;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        cin>>ll[i];
    }
    for(int i=0;i<m;i++) {
		for(int j=i;j<m;j++) {
			if(y<(ll[i]&ll[j])) y=ll[i]&ll[j];
		}
	}
	cout<<y;
    return 0;
}
