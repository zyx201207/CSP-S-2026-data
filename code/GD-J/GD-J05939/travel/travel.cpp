#include<bits/stdc++.h>
using namespace std;
char g[3]={'A','B','C'};
bool find(char x){
	for(int i=0;i<3;i++)
		if(g[i]==x) return 1;
		return 0;
}
int main(){
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin >> a1 >> a2 >> b1 >> b2;
	string s1,s2;
	for(int i=0;i<2;i++){
		s1+=a2[i];
		s2+=b2[i];
	}
	int a=a2[2];
	int b=b2[2];
	if(a1==b1){
		cout << 1;
		if(s1==s2){
			cout << 1;
			if(find(char(a))&&find(char(b))){
				cout << 1;
				if(abs(a-b)==1) cout << 1;
				else cout << 0;
			}else cout << "00";
		}else cout << "000";
	}else cout << "0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}

