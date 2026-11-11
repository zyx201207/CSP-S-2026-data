#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	if(a==c){
		cout << 1;
	}else{
		cout << "0000";
		return 0;
	}
	for(int i=0;i<b.size();i++){
		int x=b[i];
		for(int j=0;j<d.size();j++){
			int y=d[j];
			if(x!=y){
				cout << "000";
				return 0;
			}
			if((x-y==1||y-x==1)&&x!='D'&&x!='F'){
				cout << "111";
				break;
			}else{
				if((x=='D'&&y=='F')||(x=='F'&&y=='D')){
					cout << "111";
					break;
				}
				else{
					cout << "100";
					break;
				}
			}
		}
		break;
	}
	return 0;
}
