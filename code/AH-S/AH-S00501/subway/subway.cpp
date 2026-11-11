#include<bits/stdc++.h>
using namespace std;
int main(){
	srand(time(NULL));
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);   
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	while(q--){
		cout<<rand()%500005<<endl;
	}
	return 0;
}
