#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,x;
string y,a;
int main(){
    freopen("string4.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>x>>y;
    	while(x--){
    		a+=y;
		}
	}
	for(int i=0;i<a.size();i++){
		if(a[i]!=a[a.size()-1-i]) cnt++;
	}
	cout<<cnt/2;
    return 0;
}

