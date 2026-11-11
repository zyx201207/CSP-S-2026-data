#include <bits/stdc++.h>
#include <vector> 
using namespace std;
int main(){
    int n;
    vector<char> li;
    int j=0,c=0;
    cin>>n;
    for(int i;i<n;i++){
        int in1;
        char in2;
        cin>>in1>>in2;
        for(int i=0;i<in1;i++){
            li.pushback(in2);
        }
    }
    if(li.size()%2==1){
        int j=1;
    }
        for(int i=0;i<=(li.size()-j)/2-1;i++){
            if(li[i]!=li[li.size()-i-1]){
                c+=1;
            }
        }
    cout<<c;
    return 0;
    }