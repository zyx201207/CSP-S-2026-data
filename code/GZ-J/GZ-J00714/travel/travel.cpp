//  GZ-J00714  ÙFê–µÚÈıŒòÖĞŒW  ÔS¿¡ºÀ 
#include <bits/stdc++.h>
using namespace std;
char c1[105],c2[105],s1[105],s2[105];
int mian(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    
    cin >> c1 >> c2 >> s1 >> s2;
    if(s1 != s2)
    	cout  << "0000" << endl;
	else {
		if(c1[0]!=c2[0])
			cout << "1000" << endl;
		else {
			if (c1[1]!=c2[1])
				cout << "1000" << endl;
			else {
				if((c1[2]=="D" && C2[2]!="F") || (c2[2]=="D" && C1[2]!="F")||(c1[2]=="A" && ((C2[2]!="B")|| (C2[2] !="C")) )|| (c2[2]=="A" && ((C1[2]!="B")|| (c1[2]!="c")))
					cout << "1100" << endl;
				else {
					if((c1[2]=="D" && C2[2]!="F") || (c2[2]=="D" && C1[2]!="F")||(c1[2]=="A" && C2[2]!="B")|| (c2[2]=="A" && C1[2]!="B"))
						cout << "1110" << endl;
					else {
						cout << "1111" << endl;
					}
				}
			}
		}
	}
	return 0;
}
