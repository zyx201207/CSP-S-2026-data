#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out.","w",stdout);
	long long c1,s1[10005],c2,s2[10005];
	cin >> c1>>s1[10005]>>c2>>s2[10005];
	if(c1==c2||1<c1<17&&1<c2<17||(c1==1||c1==17&&c2==1||c2==17)){
		cout << 1;
	}else{
		cout << 0;
	}
	if(s1[1]==s2[1]&&s1[2]==s2[2]){
		cout << 1;
	}else{
		cout << 0;
	}
	if(s1[1]==s2[1]&&s1[2]==s2[2]&&"A"<=s1[3]<="C"||"A"<=s2[3]<="C"&&"D"<=s1[3]<="E"||"D"<=s2[3]<="E"){
		cout << 1;
	}else{
		cout << 0;
	}
	if(s1[3]=="A"&&s2[3]=="A"||s1[3]=="B"&&s2=="B"||s1[3]=="C"&&s2=="C"||s1[3]=="D"&&s2[3]=="D"||s1[3]=="F"&&s2[3]=="F"){
		cout << 1;
	}else{
		cout << 0;
	}
	return 0;
}
