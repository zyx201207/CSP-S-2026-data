#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	char ch1=s1[2],ch2=s2[2];
	int asc1=ch1,asc2=ch2; 
	int is1=1,is2=1,is3=1,is4=1;
	if(c1!=c2){//不在同一个车厢 
		is1=0;
		is2=0;
		is3=0;
		is4=0;
	}else if(!(s1[0]==s2[0]&&s1[1]==s2[1])){//在一个车厢，不在同一排 
		is2=0;
		is3=0;
		is4=0;
	}else if(!((ch1>='A'&&ch1<='C'&&ch2>='A'&&ch2<='C') || (ch1>='D'&&ch1<='F'&&ch2>='D'&&ch2<='F'))){//在同一排，不在同一侧过道 
		is3=0;
		is4=0;
	}else if((ch1=='D'||ch1=='F')&&(ch2=='D'||ch2=='F')) is4=1;//F D在同一侧 
	else if(!(max(asc1,asc2)-min(asc1,asc2)==1)){//不是F和D 在同一侧但不相邻 
		is4=0;
	}
	cout<<is1<<is2<<is3<<is4; 
	return 0;
} //A是65  66  67  D是68  69  70
