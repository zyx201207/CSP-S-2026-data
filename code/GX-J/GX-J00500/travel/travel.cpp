include<bits/stdc++.h>
using namespace std;
int main {
freopen{"travel.in",'r',stdin};
freopen{"travel.out",'w',stdout};
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
        cout<<'0000';
	}
	if(c1=c2&&s1-s2==1{
        cout<<'1111';
	}
	int sum=0;
	while(c1==c2){
        cout<<'1';
        if((s1-s2)+(s2-s1)==0){
            cout<<'1';
			if(s1>s2){
                sum=s1-s2;
				if(sum<=2){
                    cout<<'1';
                    if(s1-s2==1){
                        cout<<'1';
					}else{
                        cout<<'0';
					}
				}else{
                    cout<<'00';
				}

		}else(s1<s2){
			sum=s2-s1;
			if(sum<=2){
                cout<<'1';
                if(s2-s1==1){
                    cout<<'1';
				}else{
                    cout<<'0';
				}
			}else{
                cout<<'00';
			}
		}else{
            cout<<'000';
		}
	}
 	return 0;
}


