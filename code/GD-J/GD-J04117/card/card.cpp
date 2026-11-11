#include <iostream>
using namespace std;
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n,p,q;
	cin>>m>>n>>p>>q;
	if(m<=0){
		m =m/-1;	
	}
	if(n<=0){
		n = n*-1;
	}
	cout<<(m%3)+2<<" "<<(n%7)+1<<" ";
	int Fang=(p+q)%7+1;
	cout<<Fang-1;
	return 0;
}
