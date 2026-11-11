#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2; //输入信息 
	if(c1==c2){
		cout<<1; //如果车厢相同先打印一个1 
		if(s1[0,1]==s2[0,1]) // 如果前两位相同代表在同一行 
		{
			cout<<1;
			if( (s1[2]=='F'&&s2[2]=='F')||(s1[2]=='D'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')||(s1[2]=='F'&&s2[2]=='D')
			){
				cout<<1;
			} //判断是不是在同一侧（两个座位） 
			else if((s1[2]!='F')&&(s1[2]!='D')  &&  ((s2[2]!='F')&&(s2[2]!='D'))){
				cout<<1; //如果都不在两座位一侧，则都在三个座位一侧 
			}
			else{
				cout<<0;
			} //如果两侧都不在则输出0 
			
		}
		else{
			cout<<0<<0;
		}//不在同一行就输出两个0（不是同一行     不是同一行的同一侧） 
	}
	else{
		cout<<0<<0<<0;
	}//车厢不同则后续同一行，同一行的同一侧都为0，就是3个 
	if(s1[0,1]==s2[0,1]){
		if(s1[2]=='A'){
			if(s2[2]=='B'){
				cout<<1;
			}
			else{
				cout<<0;
			}
		} // 判断s1[2]=A座位两侧 
		
		if(s1[2]=='B'){
			if(s2[2]=='C'||s2[2]=='A'){
				cout<<1;
			}
			else{
				cout<<0;
			}
		} // 判断s1[2]=B座位两侧 

		if(s1[2]=='C'){
				if(s2[2]=='B'){
				cout<<1;
			}
			else{
				cout<<0;
			}
		} // 判断s1[2]=B座位两侧 
		if(s1[2]=='D'){
			if(s2[2]=='F'){
				cout<<1;
			}
			else{
				cout<<0;
			}
		} // 判断s1[2]=d座位两侧 
		if(s1[2]=='F'){
			if(s2[2]=='D'){
				cout<<1;
			}
			else{
				cout<<0;
			}
		} // 判断s1[2]=F座位两侧 
	}
	else{
		cout<<0;
	}
	return 0;
} 
