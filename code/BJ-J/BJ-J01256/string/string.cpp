#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){

    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    vector<pair<char, int>> strings;
    int segments;
    cin>>segments;
for (int i=0;i<segments;i++){
            char a;
            int b;
char c;
            cin>>b>>a;
            strings.push_back(pair<char, int>(a, b));

    }
    long long tochange = 0;
    while(!strings.empty()){
        pair<char, int> a = strings[0];
        pair<char, int> b = strings[strings.size()-1];
        int aval = a.second;
        int bval = b.second;
        char achar = a.first;
        char bchar = b.first;
        if (aval > bval){
            if (achar != bchar) tochange += bval;
            strings[0] = pair<char, int> (achar, aval-bval);
            strings.pop_back();
        }
        if (aval == bval){
                if (strings.size() == 1) {
                    if (achar != bchar) tochange += bval/2;
                    break;
                }
            if (achar != bchar) tochange += bval;
            strings.pop_back();
            strings.erase(strings.begin());
        }
        if (aval < bval){
            if (achar != bchar) tochange += aval;
             strings[strings.size()-1] = pair<char, int> (bchar, bval-aval);
            strings.erase(strings.begin());
        }
    }
    cout<<tochange<<endl;


    return 0;
}
