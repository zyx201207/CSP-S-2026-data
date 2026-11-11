#include<bits\stdc++.h>
using namespace std;
string  c1,c2,s1,s2;
int guodiy(char a){//过道判断 
	if(a == 'A'||a == 'B'||a == 'C')
		return 1;//1表示在左侧
	else 
		return 2;//2表示在右侧 
}
int bi_int(char a){
	if(a == 'D')a = char(a+1);
	int a1 = int(a);
	return a1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int pd1 = 0,pd2 = 0,pd3 = 0,pd4 = 0;
	if(c1 == c2){
		pd1 = 1;
		if(s1[0] == s2[0]&&s1[1] == s2[1]){
		pd2 = 1;
		//cout<<';'<<guodiy(s1[2])<<' '<<guodiy(s2[2])
		if(guodiy(s1[2]) == guodiy(s2[2]))
			pd3 = 1;
		int s3 = bi_int(s1[2]),s4 = bi_int(s2[2]);
		if(s3 -s4 == 1||s3 - s4 == -1)
			pd4 = 1;
		}
	}
	
	cout<<pd1<<pd2<<pd3<<pd4;
	return 0;
} 
