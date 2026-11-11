#include<bits/stdc++.h>
using namespace std;
string a,aa,b,bb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>a>>aa>>b>>bb;
	if(a[0]!=b[0]||a[1]!=b[1]){
		cout<<"0000";
		return 0;
	}
	if(aa[0]!=bb[0]||aa[1]!=bb[1]){
		cout<<"1000";
		return 0;
	}
	if(aa[2]>'C'&&bb[2]>'C'){
		cout<<"1111";
		return 0;
	}
	 else if(aa[2]<'D'&&bb[2]<'D'){
	 	int x,y;
	 	x=aa[2],y=bb[2];
	 	if(abs(x-y)>1){
	 		cout<<"1110";
	 		return 0;
		 }
		 else{
		 	cout<<"1111";
		 }
	 }
	 else cout<<"1100";
	return 0;
}
