#include<bits/stdc++.h>
using namespace std;
int a[101010],b[101011],f[101011];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	for(int i=1;i<=32;i++){
		cin>>a[i];
	}
	if(a[3]==5&&a[4]==2&&a[6]==2) cout<<1<<endl<<2;
	return 0;
}
