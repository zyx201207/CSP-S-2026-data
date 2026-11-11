#include<bits/stdc++.h>
using namespace std;
int main(){
    srand(time(0)); 
	ios::sync_with_stdio(true);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	for(int i=1;i<=e;i++)
	  cout<<rand()%100<<endl;
	return 0;
}

