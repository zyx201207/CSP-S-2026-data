#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int cnt=0;
	string s1,s2;
	char c1,c2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	char py[7]={1,2,3,4,5,6,7},xy[7]={1,2,3,4,5,6,7};
	if(py!=xy){
				cout<<"1";
			}
			else{
				cout<<"0";
				}
			
	for(int i=1;i<=50;i++){
		if(py[i]==xy[i+1])
			cnt=1;
			else
			cnt=0;
	}
	cout<<cnt;
	if(cnt==1||cnt==1){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}

