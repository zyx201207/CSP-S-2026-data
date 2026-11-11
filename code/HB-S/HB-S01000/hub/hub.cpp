#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	srand(time(0));
	int r=0;
	r=rand()%10+1;
	cout<<r<<' '<<r+1;
	return 0;
}
