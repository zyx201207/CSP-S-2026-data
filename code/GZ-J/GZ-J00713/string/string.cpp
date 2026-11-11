//GZ-J00713 遵义市新蒲中学 朱若鸣 
#include<bits/stdc++.h>
using namespace std;
char s[100000005];
int main(){
	int n,a,j=1,cnt=0,l=0;
	char c;
	ifstream fin;
	fin.open("string.in"); 
	ofstream fout;
	fout.open("string.out");
	fin>>n;
	for(int i=1;i<=n;i++){
		fin>>a>>c;
		l+=a;
		for(;j<=a&&j<100000001;j++) s[j]=c;
	}
	for(int i=1;i<=l/2;i++){
		if(s[i]!=s[l-i+1]) cnt++;
	}
	fout<<cnt;
	fin.close();
	fout.close();
	return 0;
}
