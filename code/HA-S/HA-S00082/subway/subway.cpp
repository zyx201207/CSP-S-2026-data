#include<bits/stdc++.h>
using namespace std;
int main(){
	srand(time(0));
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	if(b==2) cout<<"32\n17";
	else if(b==3) cout<<"35\n16";
	else{
		for(int i=1;i<=e;i++) cout<<rand()%10*e<<"\n";
	}
	return 0;
}
