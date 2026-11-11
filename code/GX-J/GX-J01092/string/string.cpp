#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int check(string a, string b){
    auto ait = a.begin();
    auto bit = b.begin();
    long long cnt=0;
    
    while(!(ait==a.end()||bit==b.end())){
        if(*ait!=*bit){
            cnt++;
        }

        ++ait;
        ++bit;
    }
    
    return cnt;
}

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int rounds;
    cin>>rounds;
    
    string input;
    for(int i=0; i<rounds; i++){
        long long n;
        char c;
        cin>>n>>c; 
        for(long long j=0; j<n; j++){
            input.push_back(c);
        }
    }
    
    //if input reverse
    string rinput = input;
    reverse(rinput.begin(), rinput.end());
    if(input.compare(rinput)==0){
        cout<<0<<endl;
        return 0;
    }
    
    long long midlong = input.size()/2;
    long long mid;
    if(input.size()%2==1)
        mid=midlong+1;
    else
        mid=midlong;
    
    //check left to right
    string ltr = input;
    string r = input.substr(0, midlong);
    reverse(r.begin(), r.end());
    ltr.replace(mid, midlong, r);
    long long ltrcnt=check(input, ltr);

    //check right to left 
    string rtl = input;
    string l = input.substr(mid, midlong);
    reverse(l.begin(), l.end());
    rtl.replace(0, midlong, l);
    long long rtlcnt=check(input, rtl);
    
    cout<<max(ltrcnt, rtlcnt)<<endl;
    return 0;
}
