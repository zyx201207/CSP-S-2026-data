//GZ-J00325 遵义航天中学 李银涛 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int pd=s1[2]-64,pd1=s2[2]-64;
	if(c1!=c2){
		cout << "0000";
		return 0;
	}
	if(s1[0]!=s2[0] || s1[1]!=s2[1]){
		cout << "1000";
		return 0;
	}
	if(pd<4 && pd1<4){
		if(abs(pd-pd1)==1){
			cout << "1111";
		}else{
			cout << "1110";
		}
	}else{
		cout << "1111";
	}
}
