#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int oop=1;
	while(m--){
		cout<<(oop++)%3+1;
	}
}
