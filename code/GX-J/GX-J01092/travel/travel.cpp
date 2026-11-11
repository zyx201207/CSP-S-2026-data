#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Seat{
public:
    string car;
    string seat;
    Seat(string c, string s){
        car=c;
        seat=s;
    }
    
    bool IsSameCar(const Seat& s){
        if(car.compare(s.car)==0){
            return true;
        }
        else{
            return false;
        }
    }
    bool IsSameRow(const Seat& s){
        if(IsSameCar(s)==false){
            return false;
        }
        
        string myRow=seat.substr(0, 2);
        string sRow=s.seat.substr(0, 2);
        if(myRow.compare(sRow)==0){
            return true;
        }
        else{
            return false;
        }
    }
    bool IsSameSide(const Seat& s){
        if(IsSameRow(s)==false)
            return false;
        
        char mySeat=seat.at(2);
        char sSeat=s.seat.at(2);
        if((mySeat>='A'&&mySeat<='C')&&(sSeat>='A'&&sSeat<='C')){
            return true;
        }
        else if((mySeat>='D'&&mySeat<='F')&&(sSeat>='D'&&sSeat<='F')){
            return true;
        }
        else{
            return false;
        }
    }
    bool IsNear(const Seat& s){
        if(IsSameSide(s)==false)
            return false;
        
        char mySeat=seat.at(2);
        char sSeat=s.seat.at(2);
        if(abs(mySeat-sSeat)==1){
            return true;
        }
        else
            return false;
    }
};

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    string rc, rs;
    cin>>rc>>rs;
    Seat R(rc, rs);  
    
    string xc, xs;
    cin>>xc>>xs;
    Seat X(xc, xs);  
    
    cout<<R.IsSameCar(X);
    cout<<R.IsSameRow(X);
    cout<<R.IsSameSide(X);
    cout<<R.IsNear(X);
    cout<<endl;
    return 0;
}
