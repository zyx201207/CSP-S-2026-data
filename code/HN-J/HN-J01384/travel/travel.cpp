#include <bits/stdc++.h>
using namespace std;
#define int long long
string a,b,c,d;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if (a!=c){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	int l1=0,l2=0,m=b.size()-1;
	char st=b[m];
	m=d.size()-1;
	char rt=d[m];
	if (b[0]==d[0] && b[1]==d[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	
	if (st=='A' || st=='B' || st=='C'){
		if (rt=='A' || rt=='B' || rt=='C'){
			cout<<"1";
		}
	}else if(st=='D' || st=='F'){
		if (rt=='D' || rt=='F'){
			cout<<"1";
		}
	}else{
		cout<<"00";
		return 0;
	}
	//cout<<endl<<st<<" "<<rt<<endl;
	if ((st=='A' && rt=='B') || (st=='B' && rt=='A') || (st=='B' && rt=='C') || (st=='C' && rt=='B')) cout<<"1";
	else cout<<"0";
	return 0;
} 
//Trick||Treat!
