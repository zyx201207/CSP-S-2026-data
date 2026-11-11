#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int train1,train2;
	string a,b;
	cin>>train1>>a>>train2>>b;
	if(train1!=train2){
		cout<<"0000";
		return 0;
	}
	if(train1==train2){
		cout<<1;
		if(a[0]==b[0]&&a[1]==b[1]){
			cout<<1;
			if((a[2]<='C'&&b[2]<='C')||((a[2]=='D'||a[2]=='F')&&(b[2]=='D'||b[2]=='F'))){
				cout<<1;
				if(abs(a[2]-b[2])==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<"00";
			}
		}
		else cout<<"000";
	}
	return 0;
}
