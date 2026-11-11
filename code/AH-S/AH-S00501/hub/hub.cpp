#include<bits/stdc++.h>
using namespace std;
int main(){
	srand(time(NULL));
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);   
	int c,t;
	cin>>c>>t;
	while(t--){
		cout<<rand()%500005<<endl;
	}
	return 0;
}
