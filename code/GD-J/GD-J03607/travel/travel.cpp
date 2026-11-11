#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s2,c2,s1;
	cin >> c1 >>s1>>c2>>s2;
	string tf = "";
	string t = "1";
	string f ="0";
	string num ="ABCDF";

	if(c1==c2){
		tf =tf+ t;	
		if(s1[1]==s2[1]){{
			tf += t;
			int fin =num.find(s1[2]);
			int fin2 =num.find(s2[2]);
			{if(fin>=0&&fin<=2&&fin2>=0&&fin<=2||fin>=3&&fin<=4&&fin2>=3&&fin<=4){
				tf += t;
				
				if(fin==1||fin2==1){tf =tf+ t;}
				else if(fin==3||fin==4||fin2==3||fin2==4);{tf = tf+t ;}
				}else;{tf = tf+ f;}
			}}
			
			}else;{
			for(int i=1;i<=2;i++){
				tf += f;
			}}
		}
	
		else;
		{
			for(int i=1;i<=3;i++){
				tf = tf+f;
			}
		}
	}
	else;
	{for(int i=0;i<=3;i++)
			tf =tf+ f;}
	
	cout << tf;
return 0;
} 
