#include <iostream>
using namespace std;
int main()
{
    froepen("string.in","r","stdin");
    froepen("string.out","w","stdout");
    int n;
    cin >> n;
    string s;
    for(int i=1;i<=n;i++){
        int p;
        char q;
        cin >> p >> q;
        for(int i=1;i<=p;i++){
            s+=q;
        }
    }
    int sum=0;
    for(int i=1;i<=s.size()/2;i++){
        if(s[i]!=s[s.size()-i+1]){
            sum++;
        }
    }
    cout << sum;
}
