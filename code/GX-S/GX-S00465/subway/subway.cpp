#include<bits/stdc++.h>
using namespace std;


int main(){
//freopen("crystal.in", "r", stdin);
//freopen("crystal.out", "w", stdout);

int num,time,case_a = 1,case_b = 1;
cin>>num>>time;
int put[500001];
for(int i=1;i<=num;i++){
    cin>>put[i];
}

int maxnumb;
int d = put[2] - put[1];
for(int i=1;i<=num;i++){
    if(put[i] + d == put[i+1]){
        case_b++;
    }
}


if(case_b == num){
    for(int cd2=1;cd2<=time;cd2++){
        int ans2 = cd2 + (ans2 * d);
        if(cd2==(num-1)){
            maxnumb = ans2;
        }
    }
}
    return 0;
}
