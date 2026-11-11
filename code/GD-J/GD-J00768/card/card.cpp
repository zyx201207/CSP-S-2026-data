#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cout<<rand()-n<<" ";
	}
	return 0;
} 
