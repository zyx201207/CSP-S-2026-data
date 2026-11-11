#include<bits/stdc++.h>
using namespace std;
int tf[5];
int zuowei[20][20];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	bool g = false;
	bool dao = false;
	bool tong = false;
	cin>>c1>>s1>>c2>>s2;
	if(c1 == c2){
		tf[1] = 1;
		g = true;
	}else{
		tf[1] = 0;
	}
	if(g == true && s1[1] == s2[1]){
		tf[2] = 1;
		dao = true;
	}else{
		tf[2] = 0;
	}
	if(dao == true && ((s1[2] <= 'C' && s2[2] <= 'C')||(s1[2]>='D' && s2[2] >= 'D'))){
		tf[3] = 1;
		tong = true;
	}else{
		tf[3] = 0;
	}
	int a = s1[2]- 'A',b = s2[2]-'A';
	if(a + 1 == b || a-1 == b || b + 1 == a||b - 1 == a){
		tf[4] = 1;
	}else{
		tf[4] = 0;
	}
	cout<<tf[1]<<tf[2]<<tf[3]<<tf[4];
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
