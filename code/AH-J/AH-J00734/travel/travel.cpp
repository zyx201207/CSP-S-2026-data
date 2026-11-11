#include<bits/stdc++.h>
using namespace std;
int main(){
	reopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a, b;
    string a1,b1;
    cin>>a>>a1>>b>>b1;
	if(a == b){
		cout<<'1';
		if(a1[0] != b1[0] || a1[1] != b1[1]){
            cout<<"0";
        }
        else{
            cout<<"1";
            if(a1[2] == 'D' && b1[2] == 'E')cout<<"11";
            
            
            else if(a1[2] == 'E' && b1[2] == 'D')cout<<"11";
            
            else if(a1[2] == 'A'){
                if(b1[2] == 'B' || b1[2] == 'C'){
                    if(b1[2] == 'B')cout<<"11";
                    else{
                        cout<<"10";
                    }
                }
                else{
                    cout<<"00";
                }

            }
            else if(a1[2] == 'B'){
                if(b1[2] == 'A' || b1[2] == 'C'){
                    cout<<"11";
                }
                else{
                    cout<<"00";
                    }
                

            }
            else if(a1[2] == 'C'){
                if(b1[2] == 'A' || b1[2] == 'B'){
                    if(b1[2] == 'B')cout<<"11";
                    else{
                        cout<<"10";
                    }
                }
                else{
                    cout<<"00";
                }
            }
            
        }
        return 0;
	}
	else{
		cout<<"0000";
	}
	return 0;
}



