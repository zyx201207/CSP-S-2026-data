#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,a1;
	string b,b1;
	cin>>a>>a1>>b>>b1;
	for(int i=0;i<=1;i++){
		if(a[i]!=b[i]){
			cout<<"0000";
			return 0;
		}
	}
	cout<<"1";
	for(int i=0;i<=1;i++){
		if(a1[i]!=b1[i]){
			cout<<"000";
			return 0;
		}
	}
	cout<<"1";
	int cnt=0;
	int cnt1=0;
	if(a1[2]=='D'||a1[2]=='F'){
		cnt=1;
	}
	if(b1[2]=='D'||b1[2]=='F'){
		cnt1=1;
	}
	if(cnt!=cnt1){
		cout<<"00";
		return 0;
	}
	cout<<"1";
	if(a1[2]-b1[2]==1||b1[2]-a1[2]==1||cnt1==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
