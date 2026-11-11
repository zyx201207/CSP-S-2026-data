//O(1)的复杂度即可完成,顺序判断即可
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<ll,ll>;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	#ifndef LOACL_RUN
        ifstream fi("travel.in");
        ofstream fo("travel.out");
        #define cout fo
        #define cin fi
	#endif
        string r_train,r_seat,x_train,x_seat;
        cin>>r_train>>r_seat>>x_train>>x_seat;
        string ans="";
        ans+=(r_train==x_train?"1":"0");
        if(ans=="0"){cout<<"0000";return 0;}
        string r_seatline=r_seat.substr(0,2);
        string x_seatline=x_seat.substr(0,2);
        ans+=(r_seatline==x_seatline?"1":"0");
        if(r_seatline!=x_seatline){cout<<ans<<"00";return 0;}
        char r_seatp=r_seat[2];
        char x_seatp=x_seat[2];
        switch(r_seatp){
                case 'A':{
                        switch(x_seatp){
                                case 'B':{ans+="11";break;}
                                case 'C':{ans+="10";break;}
                                case 'D':
                                case 'F':{ans+="00";break;}
                                default:break;
                        }break;
                }case 'B':{
                        switch(x_seatp){
                                case 'A':
                                case 'C':{ans+="11";break;}
                                case 'D':
                                case 'F':{ans+="00";break;}
                                default:break;
                        }break;
                }case 'C':{
                        switch(x_seatp){
                                case 'B':{ans+="11";break;}
                                case 'A':{ans+="10";break;}
                                case 'D':
                                case 'F':{ans+="00";break;}
                                default:break;
                        }break;
                }case 'D':{
                        switch(x_seatp){
                                case 'A':
                                case 'B':
                                case 'C':{ans+="00";break;}
                                case 'F':{ans+="11";break;}
                        }break;
                }case 'F':{
                        switch(x_seatp){
                                case 'A':
                                case 'B':
                                case 'C':{ans+="00";break;}
                                case 'D':{ans+="11";break;}
                        }break;
                }default:break;
        }
        cout<<ans;
	return 0;
}
