#include<bits/stdc++.h>
using namespace std;
string c1;
string s1;
string c2;
string s2;
int box;
int line;
int w1;
int near;//02 01A 03 01A
int main(){
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c1;
    cin>>s1;
    cin>>c2;
    cin>>s2;
    int s1_sit=(s1[0]-48)*10+(s1[1]-48);
    int s2_sit=(s2[0]-48)*10+(s2[1]-48);
    char s1_word(s1[2]);
    char s2_word(s2[2]);

    if(c1==c2)box=1;
    if(s1_sit==s2_sit && box==1){

        line=1;
        if(s1_word=='A' || s1_word=='B' || s1_word=='C'){
            if(s2_word=='A' || s2_word=='B' || s2_word=='C'){
                w1=1;
                if(s1_word=='C' && s2_word=='A'){
                    near=0;
                }else if(s1_word=='A' && s2_word=='C'){
                    near=0;
                }else{
                    near=1;
                }


            }
        }if(s1_word=='D' || s1_word=='F'){
            if(s1_word=='D' || s2_word=='F'){
                w1=1;
                near=1;


            }
        }
    }

	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	cout<<box;
	cout<<line;
	cout<<w1;
	cout<<near;








	return 0;
}
