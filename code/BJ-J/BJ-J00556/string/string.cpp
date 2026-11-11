#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string ac = "";
    while(n--){
        long long a;
        char c;
        cin>>a>>c;
        for(int i = 1; i <= a; i++ ){
            ac += c;
        }
    }
    unsigned long long sum = 0;
    for(int i = 0; i < ac.size() / 2; i++ ){
        if(ac[i] != ac[ac.size()-1-i]){
            sum++;
        }
    }
    cout<<sum<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
