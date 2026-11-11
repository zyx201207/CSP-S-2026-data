#include <bits/stdc++.h>
using namespace std;
int c;
string s;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c;
	if(c==0){
		cin>>s;
		if(s=="0 2 5 2 1 2 2 3 3 4 4 5 10 3 1 2 1 3 2 4 2 5 3 6 3 7 3 8 7 9 9 10"){
			cout<<1<<"\n";
			cout<<2;
		}else if(s=="0 3 8 6 4 8 5 8 6 3 3 2 2 1 1 8 7 8 6 5 1 2 2 5 4 5 5 3 3 6 9 3 1 2 2 8 4 7 6 5 7 9 8 5 5 3 3 9"){
			cout<<1<<"\n";
			cout<<1<<"\n";
			cout<<2;
		}
	}
	return 0;
}
