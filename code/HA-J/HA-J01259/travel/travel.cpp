#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,sum;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		sum[1]='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){//tong xiang tong pai
			sum[2]='1';
			if((s1[2]<=67&&s2[2]<=67) || (s1[2]>=68&&s2[2]>=68)){//tongpai tongce
				sum[3]='1';
				if((s1[2]-s2[2]==1)||(s1[2]-s2[2]==-1)){
					if((s1[2]==67&&s2[2]==68)||(s1[2]==68&&s2[2]==67)){//xianglin
						sum[4]='0';
					}
					else{
						sum[4]='1';
						
					}
				}
				else{
					sum[4]='0';
				}
			}
			else{
				sum[3]='0';
				sum[4]='0';
			}
		}
		else {
			sum[2]='0';
			sum[3]='0';
			sum[4]='0';
		}
			
		
	}
	else {
		sum[1]='0';
		sum[2]='0';
		sum[3]='0';
		sum[4]='0';
	}

	for(int i=1;i<=4;i++){
		cout<<sum[i];
	}
	return 0;
}
