#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cnt[5]; char C1[2]; char C2[2]; char S1[3];  char S2[3];
    for(int i=1;i<=2;i++) cin>>C1[i];
	for(int i=1;i<=3;i++) cin>>S1[i];
	for(int i=1;i<=2;i++) cin>>C2[i];
	for(int i=1;i<=3;i++) cin>>S2[i]; 
	if(C1[1]==C2[1]){ if(C1[2]==C2[2]){ cnt[1]=1;
	if(S1[1]==S2[1]){ if(S1[2]==S2[2]){ cnt[2]=1;
	if(S1[3]>=3&&S2[3]>=3||S1[3]<=2&&S2[3]<=2){ cnt[3]=1;
	if(S1[3]-S2[3]==1||S2[3]-S1[3]==1){ cnt[4]=1;
	    }else{cnt[4]=0;}
	        }else{for(int i=3;i<=4;i++) cnt[i]=0;}
				}else{for(int i=2;i<=4;i++) cnt[i]=0;}
			}
			else{for(int i=2;i<=4;i++) cnt[i]=0;}	
		}else {
		for(int i=1;i<=4;i++) cnt[i]=0;}
	}else{
	    for(int i=1;i<=4;i++) cnt[i]=0;}
	cout<<endl;
	for(int i=1;i<=4;i++) cout<<cnt[i];
	return 0;
} 
