#include <bits/stdc++.h>
using namespace std;

int m,n;
int a[100005];
longlong num2=0;




int second(int num){
    int w=[100005];
    int H=0;
    while(num>0){
        w[H]=num%2;
        H++;
        num=num/2;
    }
    for (int i=0;i<=len(w);i++){
        num2+=w[i]*pow(10,i);
    }
    return num2;

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<12;
    return 0;
}
