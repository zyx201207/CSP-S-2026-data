#include<bits/stdc++.h>
#define int long long 
#define endl "\n"
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string cx1=s1.substr(0,2),cx2=s2.substr(0,2);
	string zw1=s1.substr(2,1),zw2=s2.substr(2,1);
	if(zw1>zw2){
		swap(zw1,zw2);
	}
//	cout<<zw1<<" "<<zw2<<endl;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(c1==c2&&cx1==cx2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(c1==c2&&cx1==cx2&&(zw1[0]-'C'<=0)==(zw2[0]-'C'<=0)){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(c1==c2&&cx1==cx2&&(zw1[0]-'C'<=0)==(zw2[0]-'C'<=0)&&(zw2[0]-zw1[0]==1&&zw1[0]!='C')){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
