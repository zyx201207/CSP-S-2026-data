#include <iostream>
#include <vector>
using namespace std;
int main(){
    freopen("string.in",r,stdin);
    freopen("string.out",w,stdout);
    vector<char> a(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int h;
            cin>>h;
        char k;
            cin>>k;
        for(int j=0;j<h;j++){
            a.push_back(k);
        }

    }
    if(a.size()%2!=0){
        a.erase(a.begin()+a.size()/2);
    }
    int sum=0;
    for(int i=0;i<a.size()/2;i++){
        if(a[i]!=a[a.size()-i-1]){
            sum++;
        }
    }
    cout<<sum;

    return 0;
}
