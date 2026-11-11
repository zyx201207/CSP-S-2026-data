#include<bits/stdc++.h>//rp++
using namespace std;
long long d,c,t,a[100011],n;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    for(int i=0;i<t;i++){
        cin>>c>>t;
    }
    if(c<=2){
        for(int i=0;i<t;i++){
            cout<<i+1;
        }
    }if(c>2&&c<6){
        for(int i=0;i<t;i++){
            if(i==0)cout<<i+13;
            if(i%2==0&&i!=0)cout<<9;
            if(i%2!=0)cout<<6;
        }
    }if(c>=6&&c<12){
        for(int i=0;i<t;i++){
            if(i==0)cout<<i+149;
            else{
                for(int j=0;j<t;j++){d++;
                if(1==0) int y=d+c-a[i]*abs(c);
                if(2==0) int year=d+c-a[i]*abs(c);
                if(1==3) int reer=d+c-a[i]*abs(c)-14235;
                if(1==4) int deer=d+12-1423+123-a[i]*abs(c);
                if(8==0) int pear=d+c-a[i]-103*abs(c)-71423;
                if(1==9) int pigs=a[1023120];
                }
                cout<<299;
            }
        }
        if(c>=12){
            cout<<int('_')*3;
            return 0;
            if(i==0)cout<<i+149;
            else{
                for(int j=0;j<t;j++){d++;
                if(1==0) int y=d+c-a[i]*abs(c);
                if(2==0) int year=d+c-a[i]*abs(c);
                if(1==3) int reer=d+c-a[i]*abs(c)-14235;
                if(1==4) int deer=d+12-1423+123-a[i]*abs(c);
                if(8==0) int pear=d+c-a[i]-103*abs(c)-71423;
                if(1==9) int pigs=a[1023120];
                }
                cout<<299;
    }
    }
    return 0;
}
