#include<bits/stdc++.h>
using namespace std;
string r,r1,x,x1;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(nullptr);
cin>>r>>r1>>x>>x1;
if(r==x){
	cout<<1;
	bool b=0,a=0;
	for(int i=0;i<=1;i++){
		if(r1[i]!=x1[i]){
			cout<<"000";
			b=1;
			a=1;
			break;
		}
	}
	if(b==0){
		cout<<1;
		if(('A'<=r1[2]&&r1[2]<='C'&&'A'<=x1[2]&&x1[2]<='C')||('D'<=r1[2]&&r1[2]<='F'&&'D'<=x1[2]&&x1[2]<='F')){
			cout<<1;
		}else{
			cout<<"00";
			a=1;
		}
	}
	if(a==0){
		if(r1[2]+1==x1[2]||r1[2]==x1[2]+1){
			cout<<1;
		}else{
			cout<<"0";
		}
	}
}else{
	cout<<"0000";
}
cout<<"\n";
return 0;
}
