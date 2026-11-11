#include<iostream>
#include<cstdio>

using namespace std;
char s[200000000];
int n;
long long num = 0;
void read(){

    cin >> n;
    for(int i = 0;i<n;i++){
        long long a;
        char c;
        cin >> a >> c;
        for(long long j = 0;j < a;j++){
            s[num] = c;
            num++;
        }
    }
}

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    read();
    /*for(int i = 0;i<num;i++){
        cout << s[i];
    }*/
    long long l = 0 , r = num - 1;
    long long cnt = 0;
    while(r>=l){
        if(s[l]!=s[r]){
            cnt ++;
        }
        r--;
        l++;
    }
    cout << cnt;
    return 0;
}