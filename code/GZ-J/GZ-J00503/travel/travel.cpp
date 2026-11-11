//GZ-J00503 ¶ÅÓÀå·
#include<bits/stdc++.h>

using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    char h1,h2;
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    h1=s1[2];
    h2=s2[2];

    if(c1[0]==c2[0]&&c1[1]==c2[1]){
        cout<<'1';
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<'1';
		    if(h1<'D'&&h2<'D'||h1>'C'&&h2>'C'){
            	cout<<'1';
            	if(h2-h1==1||h2-h1==-1)
                	cout<<'1';
            	else
                	cout<<'0';
		
            
            }
        	else
            	cout<<"00";
        
        
                
            

            }
        else
            cout<<"000";
 


        }
    else
        cout<<"0000";




return 0;
}
