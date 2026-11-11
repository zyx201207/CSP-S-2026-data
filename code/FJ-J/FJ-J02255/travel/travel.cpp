#include<bits/stdc++.h>
using namespace std;
string r_2,x_2;
int r_1,x_1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>r_1>>r_2>>x_1>>x_2;
	int a=r_2[0]+r_2[1],b=x_2[0]+x_2[1];
	int c=r_2[2],_d=x_2[2];

	if(r_1==x_1){
		cout<<"1";
		if(a==b){
			cout<<"1";
			if(c+_d=='A'+'B'||c+_d=='A'+'C'||c+_d=='D'+'F'){
				cout<<"1";
				if(c+_d=='A'+'B'+0||c+_d=='D'+'F'+0){
					cout<<"1";
				}else {
					cout<<"0";
				}
			}else {
				cout<<"00";
			}
		}else {
			cout<<"000";
		}
	}else {
		cout<<"0000";
	}
	return 0;
}
