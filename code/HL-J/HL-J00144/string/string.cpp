#include<bits/stdc++.h>
using namespace std;
char a[200005];
int main(){
    freopen{"string.in","r",stdin};
    freopen{"string.out","w",stdout};
    int n;
    cin>>n;
    char cnt;
    for (int i=1;i<=n*2;i++){
    	cin>>a[i];
	}
	if (a[2]==a[n*2]){
		cout<<"0";
		return 0;
	}
	if (a[1]!=a[n*2-1]){
		if (a[1]>=a[n*2-1]){
			cnt+=a[1];
		}
		else if (a[1]<a[n*2-1]){
			cnt+=a[n*2-1];
			cnt+=a[n*2-1]-a[1];
		}
	}
	cout<<cnt;
	return 0;
} 

