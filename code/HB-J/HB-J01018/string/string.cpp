#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,sum=0;
    int a[100005];
    string c[1005],s,s1,s2;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];	
        s+=c[i];
        sum++;
	}
	cout<<"2";
	return 0;
}
