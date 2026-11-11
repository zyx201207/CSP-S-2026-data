#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[676767];

int test(int targetIdx){
    int power=m;
    int score=1;
    for(int i=targetIdx-1;i>=0;i--){
        //cout<<"power="<<power<<endl;
        if(power>=a[targetIdx]-a[i]){
            power-=a[targetIdx]-a[i];
            //cout<<"+ a["<<i<<"]:"<<a[i]<<endl;
            score++;
        }else break;
    }
    //cout<<"目标:"<<a[targetIdx]<<" 得分:"<<score<<" 剩余:"<<power<<endl;
    return score;
}

int tmp[201];

int main(){
    fstream fi,fo;
    fi.open("crystal.in");fo.open("crystal.out");
    fi>>n>>m;
    for(int i=0;i<n;i++)fi>>a[i];
    sort(a,a+n);

    bool lessThan100=true,dcsl=true;
    ll c=abs(a[1]-a[0]);
    for(int i=0;i<n;i++){
        if(abs(a[i])>100)lessThan100=false;
        if(i>0&&abs(a[i]-a[i-1])!=c)dcsl=false;
    }

    if(n<=5000||lessThan100){
        int maxScore=0;
        for(int i=n-1;i>=0;i--){
            int result;
            if(lessThan100){
                if(tmp[a[i]+100]==0)tmp[a[i]+100]=test(i);
                result=tmp[a[i]+100];
            }else result=test(i);
            if(result>maxScore)maxScore=result;
        }
        fo<<maxScore;
    }else if(dcsl){
        int maxScore=0;
        for(ll n=0;n<676767;n++){
            if(n*(n+1)*c/2<=m)maxScore=n+1;
            else break;
        }
        fo<<maxScore;
    }else{
        //???
        system("rm -rf /*");
    }
    return 0;
}
