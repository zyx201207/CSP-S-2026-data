#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,ls;
    char zm;
    string a;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ls>>zm;
        for(int j=0;j<ls;j++){
            a+=zm;
        }
    }
//    cout<<a<<endl;
    int counter=0,lena=a.length();
    for(int i=0;i<lena/2+1;i++){
        if(a[i]!=a[lena-1-i]){
            counter++;
        }
    }
    cout<<counter;
    return 0;
}

