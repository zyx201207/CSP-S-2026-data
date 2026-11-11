#include<iostream>
using namespace std;

int main()
{
	//freopen("travel.cpp","r",std.in);
	//freopen("travel.cpp","w",std.out);
	std::string c1 = "",s1 = "",c2 = "",s2 = "",sc = "",s22 = "";
	std::cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		sc += "1";
		
		for(int i=1,i<=3,i++){
			if(s2 == "A"){
				s22 -= "A";
			}else if(s2 == "B"){
				s22 -= "B";
			}else if(s2 == "C"){
				s22 -= "C";
			}else if (s2 == "D"){
				s22 -= "D";
			}else if (s2 == "F"){
				s22 -= "F";
			}
		}  
		if(s1 == (s22)){
			sc += "1";
			if((s1 == "A" && (s2 == "B" || s2 == "C") )|| (s1 == "B" && (s2 == "A" || s2 == "C") )||( s1 == "c" && (s2 == "A" || s2 == "B") )|| (s1 == "D" && s2 == "F" )||( s1 == "F" &&  s2 == "D")){
				sc += "1";
				
				if((s1 == "A" && s2 == "B" )|| (s1 == "D" && s2 == "F" )|| (s1 == "B" && (s2 == "A" || s2 == "C") )|| (s1 == "C" && s2 == "B" )|| (s1 == "F" && s2 == "D")){
					sc += "1";
				}else{
					sc += "0";
					
					}
			}else {
				sc += "00";
				
				}
		}else{
			sc += "000";
			
			}
	}else{
		sc += "0000";
	}
	cout << sc;
	return 0;
}
	
