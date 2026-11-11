#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    freopen("string .in",'r',stdin)
    freopen("string.out",'w',stdout)
    int L;
    cin>>L;
    int sum=0;
    int a[100000];
    int b[100000];
    for(int i=0;i<L;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=0;i<L;i++){
        sum=a[i]*b[i]+sum;
    }


return 0;

}
