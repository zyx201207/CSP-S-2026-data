#include <bits/stdc++.h>
using namespace std;
string s,ss,c,cc;
int main(){
    string a[5]={"A","B","C","D","F"}; 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c==cc) cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	string sub_1=s.substr(0,2),sub_2=ss.substr(0,2);
	if(sub_1==sub_2) cout<<1;
	else{
		cout<<"000";
		return 0;
	} 
	string la_1=s.substr(2,1),la_2=ss.substr(2,1);
	if(la_1=="A"||la_1=="B"||la_1=="C"){
		if(la_2=="D"||la_2=="F"){
			cout<<0;
		}
		else
			cout<<1;
	}
	if(la_1=="D"||la_1=="F"){
		if(la_2=="D"||la_2=="F"){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	unsigned long long b;
	for(int i=1;i<6;i++){
		if(a[i]==la_1){
			b=i;
			break;
		}
	}
	if(la_2==a[b-1]||la_2==a[b+1]) cout<<1;
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
//五五五，这次完了！ 
