#include<bits/stdc++.h>
using namespace std;
long long b[1000010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,a,max=0;
    cin>>n>>a;
    for(int i=0;i<0;i++){
    	cin>>b[i];
    	if(max<b[i])max=b[i];
	}
	cout<<max;
    return 0;
}
