#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
typedef long long ll;
int n,m,a[N];
string s;

int main(){
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		char x=(char)a[i]+48;
		cout<<s.find(x);
	}
    return 0;
}

