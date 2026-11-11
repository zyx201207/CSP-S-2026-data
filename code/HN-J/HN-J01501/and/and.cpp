#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	 int n,m;
	 cin>>n>>m;
	 int c=0;
	 for(int i=1;i<=n;i++){
	 	int x;
	 	cin>>x;
	 	if(c==x){
	 		cout<<x;
		 }else if(c>x){
		 	cout<<c;
		 }
		 c++;
		 x+=c;
	 }
	 cout<<c;
	return 0;
}
