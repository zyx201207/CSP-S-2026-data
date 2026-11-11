#include<bits/stdc++.h>
using namespace std;

int c1,c2;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>c1>>c2;
	for(int i=0;i<c2;i++){
		cout<<c1<<" ";
		c1--;
	}
	return 0;
}
