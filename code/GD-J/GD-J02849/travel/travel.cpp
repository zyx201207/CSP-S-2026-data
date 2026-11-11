#include<iostream>
#include<string>
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	std::string x1,y1,x2,y2;
	bool yes=0;
	std::cin>>x1>>y1>>x2>>y2;
	if(x1==x2){
		std::cout<<"1";
		yes=1;
	}
	else{
		std::cout<<"0";
		yes=0;
	}
	if(yes){
		if(y1[0]==y2[0] && y1[1]==y2[1]){
			std::cout<<"1";
			if(((int)(y1[2]-'A'+1)<=3 && (int)(y2[2]-'A'+1)<=3) || ((int)(y1[2]-'A'+1)>=4 && (int)(y2[2]-'A'+1)>=4)){
				std::cout<<"1";
				if((int)(y1[2]-y2[2])==1 || (int)(y2[2]-y1[2]==1)){
					std::cout<<"1";
				}
				else{
					std::cout<<"0";
				}
			}
			else{
				std::cout<<"00";
			}
		}
		else{
			std::cout<<"000";
		}
	}
	else{
		std::cout<<"000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
