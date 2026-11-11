#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
    string train1,train2;
    string seat1,seat2;
    cin>>train1>>seat1>>train2>>seat2;

    if(train1!=train2) {
        cout<<"0000";
        return 0;
    }
    else {
        cout<<'1';
    }

    if(seat1[0]==seat2[0]&&seat1[1]==seat2[1]) {
        cout<<'1';
    }
    else {
        cout<<"000";
        return 0;
    }

    if(seat1[2]>='D') {
        if(seat2[2]>='D') {
            cout<<"11";
            return 0;
        }
        else {
            cout<<"00";
            return 0;
        }
    }
    else {
        if(seat2[2]>='D') {
            cout<<"00";
            return 0;
        }
        else {
            cout<<'1';
        }
    }

    if(abs(seat1[2]-seat2[2])==1) {
        cout<<'1';
    }
    else {
        cout<<'0';
    }
}

