#include<bits/stdc++.h>
using namespace std;

int l = 0,w=0;
int sum[6];
int c22[4],c11[4];
string r;
string c1,s1,c2,s2;
string p1,p2;

int isnumber(char numbers){
    if (numbers - '0' < 48 || numbers - '0' > 58) return 0;
    return 1;
}

int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r;


    for (int i=0;i<=r.size()+1;i++){
        c1 = c1 + r[i];
        l++;
        if (r[i] == '\0'){
            break;
        }
    }



    cin>>s1;

    cin>>c2;

    cin>>s2;

    for (int c=0;c<=1;c++){
        c11[c] += c1[c];
        c22[c] += c2[c];
    }


    if (c11[0]==c22[0]&&c11[1]==c22[1]){
        sum[0] += 1;
    }
    else{
        for (int i=0;i<=3;i++){
            cout << sum[i];
        }
        return 0;
    }



    for (int i=0;i<=1;i++){
        p1 = p1 + s1[i];
    }
    for (int i=0;i<=1;i++){
        p2 = p2 + s2[i];
    }

    if (p1==p2){
        sum[1] += 1;
        w+=1;
    }



    int a = s1[2];
    int b = s2[2];
    if (w==1){
        if (a == 70 && b == 68){
            sum[2] += 1;
            sum[3] += 1;
            for (int i=0;i<=3;i++){
                cout << sum[i];
            }
            return 0;
        }

        if (a == 65 && (b == 66 || b == 67)){
            sum[2] += 1;
            if (b==66) sum[3] += 1;
        }

        else if (a == 66 && (b==65||b==67)){
            sum[2] += 1;
            sum[3] += 1;
        }

        else if (a == 67 && (b==65||b==66)){
            sum[2] += 1;
            if (b == 66) sum[3]+=1;
        }
    }



    for(int i=0;i<=3;i++){
        cout << sum[i];
    }

    return 0;
}
