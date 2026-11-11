#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,a1,b,b1;
string x,y;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>x>>b>>b1>>y;
	//cout<<a<<" "<<a1<<" "<<x;
	if(a==b){
		cout<<1;
		if(a1==b1){
			cout<<1;
			if((x=="A"||x=="B"||x=="C"&& y=="A"||y=="B"||y=="C") || (x=="D"||x=="F" && y=="D"||y=="F")){
				cout<<1;
				if((x=="A"&&y=="B"||y=="A"&&x=="B")||(x=="B"&&y=="C"||y=="C"&&x=="B")||(x=="D"&&y=="F"||y=="F"&&x=="D")){
					cout<<1;
				}
				else cout<<"0"<<endl;
			}
			else cout<<"00"<<endl;
		}
		else cout<<"000"<<endl;
	}
	else cout<<"0000";
	return 0;
}
//Trick||Treat!
//Ô­ÉñÆô¶¯£¡ 
