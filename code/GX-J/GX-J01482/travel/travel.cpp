#include <bits/stdc++.h>
using namespace std;

struct r{
    int chexiang;
    string zuowei;
};
struct x{
    int chexiang;
    string zuowei;
};

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int s[4] = {0};
    cin >> r.chexiang >> r.zuowei;
    cin >> x.chexiang >> x.zuowei;
    if(r.chexiang == x.chexiang){
        s[0] = 1;
    }else{
        for(int i=0; i<4; i++){
            s[i] = 0;
        }
    }
    if(r.zuowei == "01A" or r.zuowei == "01B" or r.zuowei == "01C" or r.zuowei == "01D" or r.zuowei == "01F" and x.zuowei == "01A" or x.zuowei == "01B" or x.zuowei == "01C" or x.zuowei == "01D" or x.zuowei == "01F"){
        s[1] = 1;
    }else if(r.zuowei == "02A" or r.zuowei == "02B" or r.zuowei == "02C" or r.zuowei == "02D" or r.zuowei == "02F" and x.zuowei == "02A" or x.zuowei == "02B" or x.zuowei == "02C" or x.zuowei == "02D" or x.zuowei == "02F"){
        s[1] = 1;
    }else if(r.zuowei == "03A" or r.zuowei == "03B" or r.zuowei == "03C" or r.zuowei == "03D" or r.zuowei == "03F" and x.zuowei == "03A" or x.zuowei == "03B" or x.zuowei == "03C" or x.zuowei == "03D" or x.zuowei == "03F"){
        s[1] = 1;
    }else if(r.zuowei == "04A" or r.zuowei == "04B" or r.zuowei == "04C" or r.zuowei == "04D" or r.zuowei == "04F" and x.zuowei == "04A" or x.zuowei == "04B" or x.zuowei == "04C" or x.zuowei == "04D" or x.zuowei == "04F"){
        s[1] = 1;
    }else if(r.zuowei == "05A" or r.zuowei == "05B" or r.zuowei == "05C" or r.zuowei == "05D" or r.zuowei == "05F" and x.zuowei == "05A" or x.zuowei == "05B" or x.zuowei == "05C" or x.zuowei == "05D" or x.zuowei == "05F"){
        s[1] = 1;
    }else if(r.zuowei == "06A" or r.zuowei == "06B" or r.zuowei == "06C" or r.zuowei == "06D" or r.zuowei == "06F" and x.zuowei == "06A" or x.zuowei == "06B" or x.zuowei == "06C" or x.zuowei == "06D" or x.zuowei == "06F"){
        s[1] = 1;
    }else if(r.zuowei == "07A" or r.zuowei == "07B" or r.zuowei == "07C" or r.zuowei == "07D" or r.zuowei == "07F" and x.zuowei == "07A" or x.zuowei == "07B" or x.zuowei == "07C" or x.zuowei == "07D" or x.zuowei == "07F"){
        s[1] = 1;
    }else if(r.zuowei == "08A" or r.zuowei == "08B" or r.zuowei == "08C" or r.zuowei == "08D" or r.zuowei == "08F" and x.zuowei == "08A" or x.zuowei == "08B" or x.zuowei == "08C" or x.zuowei == "08D" or x.zuowei == "08F"){
        s[1] = 1;
    }else if(r.zuowei == "09A" or r.zuowei == "09B" or r.zuowei == "09C" or r.zuowei == "09D" or r.zuowei == "09F" and x.zuowei == "09A" or x.zuowei == "09B" or x.zuowei == "09C" or x.zuowei == "09D" or x.zuowei == "09F"){
        s[1] = 1;
    }else if(r.zuowei == "10A" or r.zuowei == "10B" or r.zuowei == "10C" or r.zuowei == "10D" or r.zuowei == "10F" and x.zuowei == "10A" or x.zuowei == "10B" or x.zuowei == "10C" or x.zuowei == "10D" or x.zuowei == "10F"){
        s[1] = 1;
    }else if(r.zuowei == "11A" or r.zuowei == "11B" or r.zuowei == "11C" or r.zuowei == "11D" or r.zuowei == "11F" and x.zuowei == "11A" or x.zuowei == "11B" or x.zuowei == "11C" or x.zuowei == "11D" or x.zuowei == "11F"){
        s[1] = 1;
    }else if(r.zuowei == "12A" or r.zuowei == "12B" or r.zuowei == "12C" or r.zuowei == "12D" or r.zuowei == "12F" and x.zuowei == "12A" or x.zuowei == "12B" or x.zuowei == "12C" or x.zuowei == "12D" or x.zuowei == "12F"){
        s[1] = 1;
    }else if(r.zuowei == "13A" or r.zuowei == "13B" or r.zuowei == "13C" or r.zuowei == "13D" or r.zuowei == "13F" and x.zuowei == "13A" or x.zuowei == "13B" or x.zuowei == "13C" or x.zuowei == "13D" or x.zuowei == "13F"){
        s[1] = 1;
    }else if(r.zuowei == "14A" or r.zuowei == "14B" or r.zuowei == "14C" or r.zuowei == "14D" or r.zuowei == "14F" and x.zuowei == "14A" or x.zuowei == "14B" or x.zuowei == "14C" or x.zuowei == "14D" or x.zuowei == "14F"){
        s[1] = 1;
    }else if(r.zuowei == "15A" or r.zuowei == "15B" or r.zuowei == "15C" or r.zuowei == "15D" or r.zuowei == "15F" and x.zuowei == "15A" or x.zuowei == "15B" or x.zuowei == "15C" or x.zuowei == "15D" or x.zuowei == "15F"){
        s[1] = 1;
    }else if(r.zuowei == "16A" or r.zuowei == "16B" or r.zuowei == "16C" or r.zuowei == "16D" or r.zuowei == "16F" and x.zuowei == "16A" or x.zuowei == "16B" or x.zuowei == "16C" or x.zuowei == "16D" or x.zuowei == "16F"){
        s[1] = 1;
    }else if(r.zuowei == "17A" or r.zuowei == "17B" or r.zuowei == "17C" or r.zuowei == "17D" or r.zuowei == "17F" and x.zuowei == "17A" or x.zuowei == "17B" or x.zuowei == "17C" or x.zuowei == "17D" or x.zuowei == "17F"){
        s[1] = 1;
    }else if(r.zuowei == "18A" or r.zuowei == "18B" or r.zuowei == "18C" or r.zuowei == "18D" or r.zuowei == "18F" and x.zuowei == "18A" or x.zuowei == "18B" or x.zuowei == "18C" or x.zuowei == "18D" or x.zuowei == "18F"){
        s[1] = 1;
    }else{
        s[1] = 0;
        s[2] = 0;
        s[3] = 0;
    }

    if(r.zuowei == "01A" or r.zuowei == "01B" or r.zuowei == "01C" and x.zuowei == "01A" or x.zuowei == "01B" or x.zuowei == "01C"){
        s[2] = 1;
    }else if(r.zuowei == "02A" or r.zuowei == "02B" or r.zuowei == "02C" and x.zuowei == "02A" or x.zuowei == "02B" or x.zuowei == "02C"){
        s[2] = 1;
    }else if(r.zuowei == "03A" or r.zuowei == "03B" or r.zuowei == "03C" and x.zuowei == "03A" or x.zuowei == "03B" or x.zuowei == "03C"){
        s[2] = 1;
    }else if(r.zuowei == "04A" or r.zuowei == "04B" or r.zuowei == "04C" and x.zuowei == "04A" or x.zuowei == "04B" or x.zuowei == "04C"){
        s[2] = 1;
    }else if(r.zuowei == "05A" or r.zuowei == "05B" or r.zuowei == "05C" and x.zuowei == "05A" or x.zuowei == "05B" or x.zuowei == "05C"){
        s[2] = 1;
    }else if(r.zuowei == "06A" or r.zuowei == "06B" or r.zuowei == "06C" and x.zuowei == "06A" or x.zuowei == "06B" or x.zuowei == "06C"){
        s[2] = 1;
    }else if(r.zuowei == "07A" or r.zuowei == "07B" or r.zuowei == "07C" and x.zuowei == "07A" or x.zuowei == "07B" or x.zuowei == "07C"){
        s[2] = 1;
    }else if(r.zuowei == "08A" or r.zuowei == "08B" or r.zuowei == "08C" and x.zuowei == "08A" or x.zuowei == "08B" or x.zuowei == "08C"){
        s[2] = 1;
    }else if(r.zuowei == "09A" or r.zuowei == "09B" or r.zuowei == "09C" and x.zuowei == "09A" or x.zuowei == "09B" or x.zuowei == "09C"){
        s[2] = 1;
    }else if(r.zuowei == "10A" or r.zuowei == "10B" or r.zuowei == "10C" and x.zuowei == "10A" or x.zuowei == "10B" or x.zuowei == "10C"){
        s[2] = 1;
    }else if(r.zuowei == "11A" or r.zuowei == "11B" or r.zuowei == "11C" and x.zuowei == "11A" or x.zuowei == "11B" or x.zuowei == "11C"){
        s[2] = 1;
    }else if(r.zuowei == "12A" or r.zuowei == "12B" or r.zuowei == "12C" and x.zuowei == "12A" or x.zuowei == "12B" or x.zuowei == "12C"){
        s[2] = 1;
    }else if(r.zuowei == "13A" or r.zuowei == "13B" or r.zuowei == "13C" and x.zuowei == "13A" or x.zuowei == "13B" or x.zuowei == "13C"){
        s[2] = 1;
    }else if(r.zuowei == "14A" or r.zuowei == "14B" or r.zuowei == "14C" and x.zuowei == "14A" or x.zuowei == "14B" or x.zuowei == "14C"){
        s[2] = 1;
    }else if(r.zuowei == "15A" or r.zuowei == "15B" or r.zuowei == "15C" and x.zuowei == "15A" or x.zuowei == "15B" or x.zuowei == "15C"){
        s[2] = 1;
    }else if(r.zuowei == "16A" or r.zuowei == "16B" or r.zuowei == "16C" and x.zuowei == "16A" or x.zuowei == "16B" or x.zuowei == "16C"){
        s[2] = 1;
    }else if(r.zuowei == "17A" or r.zuowei == "17B" or r.zuowei == "17C" and x.zuowei == "17A" or x.zuowei == "17B" or x.zuowei == "17C"){
        s[2] = 1;
    }else if(r.zuowei == "18A" or r.zuowei == "18B" or r.zuowei == "18C" and x.zuowei == "18A" or x.zuowei == "18B" or x.zuowei == "18C"){
        s[2] = 1;
    }else{
        S[2] = 0;
        s[3] = 0;
    }
    for(int i=0; i<4; i++){
        cout << s[i];
    }


    return 0;
}
