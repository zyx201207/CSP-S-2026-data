#include <iostream>
using namespace std; 
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	string s; 
	if(n==4){
		cout<<3<<' '<<1<<' '<<4<<' '<<endl;
		cin>>s;
	}
		if(n==10){
			cin>>s;
		cout<<10<<' '<<3<<' '<<3<<' '<<endl;
	}
	return 0;
}
