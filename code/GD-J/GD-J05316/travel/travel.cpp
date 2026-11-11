#include <bits/stdc++.h>
const char key[5][4]={
	{'A','C','B','C'},
	{'B','C','A','C'},
	{'C','C','A','B'},
	{'D','B','F'},
	{'F','B','D'},
};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::string a1,a2,b1,b2;
	std::cin>>a1>>a2>>b1>>b2;
	std::cout<<(a1==b1);
	if((a1==b1)){
		std::cout<<(a2[0]==b2[0]&&a2[1]==b2[1]);
		if(a2[0]==b2[0]&&a2[1]==b2[1]){
			char a=a2[2],b=b2[2];
			bool flag=0;
			for(int i=0;i<5;i++){
				if(key[i][0]==a){
					for(int j=2;j<2+int(key[i][1]-'A');j++){
						if(key[i][j]==b){
							flag=1;
							break;
						}
					}
				}
			}
			std::cout<<flag;
			if(flag)std::cout<<(abs(a-b)<=1);
			else std::cout<<"0";
		}
		else std::cout<<"00";
	}
	else std::cout<<"000";
	return 0;
}
