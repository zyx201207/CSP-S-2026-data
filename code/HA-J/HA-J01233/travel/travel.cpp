#include<bits/stdc++.h>
using namespace std;
char s1[100005],s2[100005];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	cin>>c1;
	for(int i=1;i<=3;i++){
		cin>>s1[i];
	}
	cin>>c2;
	for(int i=1;i<=3;i++){
		cin>>s2[i];
	}
	
	if(c1==2&&c2==2){
		cout<<1;
	}
	else cout<<0;
	
	if(s1[1]==s2[1]&&s1[2]==s2[2]){
		cout<<1;
	}
	else cout<<0;
	
	if(s1[2]==s2[2]==1){
		cout<<1;
	}
	else cout<<0;
	
	if(s2[3]-s1[3]==1){
		cout<<1;
	}
	else cout<<0;
	return 0;
}
