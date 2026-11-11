#include<bits/stdc++.h>
using namespace std;
bool flag[2000];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	flag[int('F')]=flag[int('D')]=1;
	int a,b;
	string c,d;
	cin>>a>>c>>b>>d;
	if(a!=b){
		cout<<"0000";
	}else{
		cout<<1;
		if(c[1]+c[0]*10!=d[1]+d[0]*10){
			cout<<"000";
		}else{
			cout<<1;
			if(flag[int(c[2])]!=flag[int(d[2])]){
				cout<<"00";
			}else{
				cout<<1;
				if(c[2]+1==d[2]||c[2]==d[2]+1){
					cout<<1;
				}else{
					cout<<0;
				}
			}
		}
	}
	return 0;
}
