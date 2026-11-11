//GZ-J00713 遵义市新蒲中学 朱若鸣 
#include<bits/stdc++.h>
using namespace std;
int main(){
	int cnt[5]={0};
	int a1[4],b1[4],a2[4],b2[4];
	string c1,s1,c2,s2;
	ifstream fin;
	fin.open("travel.in");
	ofstream fout;
	fout.open("travel.out");
	fin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++){
		a1[i]=c1[i];
		a2[i]=c2[i];
	}
	for(int i=0;i<3;i++){
		b1[i]=s1[i];
		b2[i]=s2[i];
	}
	for(int i=0;i<2;i++) if(a1[i]==a2[i]) cnt[1]++;
	if(cnt[1]=2) fout<<1;
	else fout<<0;
	for(int i=0;i<2;i++) if(b1[i]==b2[i]) cnt[2]++;
	if(cnt[2]=2) fout<<1;
	else fout<<0;
	if((b1[2]<='C'&&b2[2]<='C'||b1[2]>='D'&&b2[2]>='D')&&cnt[2]==2){
		cnt[3]++;
		fout<<1;
	}
	else fout<<0;
	if((b1[2]+1==b2[2]||b1[2]-1==b2[2])&&cnt[3]==1) fout<<1;
	else fout<<0;
	fin.close();
	fout.close();
	return 0;
}
