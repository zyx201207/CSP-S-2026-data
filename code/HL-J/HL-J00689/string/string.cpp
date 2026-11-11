#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	int n,m;
	cin>>n;
	string a,b;
	for(int i=1;i<=n;i++){
        cin>>m>>a[i];

	}
    int cnt=1;
    for(int i=1;i<=n;i++){
        if(a[i]==a[i+1]){
            cnt++;
        }
    }

    if(cnt==n){
        cout<<0;
    }
    else{
        cout<<0;
    }

    return 0;
}
