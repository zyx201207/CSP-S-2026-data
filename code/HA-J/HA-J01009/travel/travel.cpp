#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string sx,s1,s2,sy;
	cin>>s1>>sx>>s2>>sy;
	if(s1==s2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(sx[1]==sy[1]&&sx[0]==sy[0]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	int a[900];
	a['A']=1;
	a['B']=1;
	a['C']=1;
	a['D']=2;
	a['F']=2;
	if(a[sx[2]]==a[sy[2]]){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	a['A']=-1;
	a['B']=0;
	a['F']=1;
	if(abs(a[sx[2]]-a[sy[2]])==1){
		cout<<1;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//02 01A 03 01A
