#include<bits/stdc++.h>
using namespace std;
int n;
    long long sum;
struct duan{
    long long pos;
    int num;
    char data;
};
duan s[100005];
char getdata(int p){
    for(int i=1;i<=n;i++){
        if(p<=s[i].pos){
            return s[i].data;
        }
    }
}
long long jiancha(){
    long long sum1=0;
    long long start=sum/2+1;
    if(sum%2==1){
        start++;
    }
    for(int i=start;i<=sum;i++){
            if(getdata(i)!=getdata(sum-i+1)){
                  //  cerr << i << endl;
             //cerr <<"data:"<< getdata(i) <<" "<<getdata(sum-i+1)<<endl;
                sum1++;
            }
    }
    return sum1;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> s[i].num >> s[i].data;
        sum+=s[i].num;
        s[i].pos=sum;
    }
        //for(int i=1;i<=sum;i++){
     //       cerr << getdata(i);
      // }
    //cerr << sum <<endl;
       //cerr << jiancha();
        cout << jiancha();
    return 0;
}
