#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long zh=0;
    long long sum=0;
    long long shu;
    char zi;
    char dui;
    for(int i=0;i<n;i++) {
        cin>>shu;
        if(shu%2==0) {
        sum=sum+shu/2;
        }
        if(i==0) {
        cin>>zi;
        continue;
        }
        cin>>dui;
        if(dui!=zi) {
        zh=1;
        }
    }
    if(zh==0) {
    cout<<"0";
    return 0;
    }
    cout<<sum;
    return 0;
}
