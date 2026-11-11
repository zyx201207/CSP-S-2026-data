#include<bits/stdc++.h>
using namespace std;
int n,q;
int main(){
	cout.tie(0);
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w","stdout");
	cin>>n>>n>>q>>q>>q;
	for(int i=0;i<q;i++){
		cout<<rand()%n<<endl;
	}return 0;
}