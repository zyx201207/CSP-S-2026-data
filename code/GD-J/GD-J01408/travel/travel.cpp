#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    int c1,c2,p1,p2,l1,l2;
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    c1=(s1[0]-48)*10+s1[1]-48;
    c2=(s3[0]-48)*10+s3[1]-48;
    p1=(s2[0]-48)*10+s2[1]-48;
    p2=(s4[0]-48)*10+s4[1]-48;
    l1=s2[2]-'A'+1;
    l2=s4[2]-'A'+1;
    int q1,q2,q3,q4;
    if(c1==c2){
    	q1=1;
    	if(p1==p2){
    		q2=1;
    		if((1<=l1 and l1<=3 and 1<=l2 and l2<=3) or (4<=l1 and l1<=5 and 4<=l2 and l2<=5)){
    			q3=1;
    			if(abs(l1-l2)==1){
    				q4=1;
				}else{
					q4=0;
				}
			}else{
				q3=q4=0;
			}
		}else{
			q2=q3=q4=0;
		}
	}else{
		q1=q2=q3=q4=0;
	}
	printf("%d%d%d%d",q1,q2,q3,q4);
	return 0;
}
