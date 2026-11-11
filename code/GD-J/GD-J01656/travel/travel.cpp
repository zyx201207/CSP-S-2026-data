#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2) cout<<'1';
	else{
		cout<<"0000";
		return 0;
	}
	
	bool flag=s1[0]==s2[0]&&s1[1]==s2[1];  //是否在同一节车厢的同一排；
	if(flag) cout<<'1'; 
	else cout<<'0';
	
	bool tmp=flag&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'));  //是否在同一节车厢的同一排，且位于过道的同一侧；
	if(tmp) cout<<'1';
	else cout<<'0';
	
	bool ans=(s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F');
	if(tmp&&ans) cout<<'1';
	else cout<<'0';
	cout<<flush;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
