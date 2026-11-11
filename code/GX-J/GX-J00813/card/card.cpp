#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int n,m;
int main(){
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=n;i>0;i--){
		cin>>a[i];
		cout<<a[i]<<" ";
		}
	
    return 0;
}

