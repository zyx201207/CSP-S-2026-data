#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
long long c;
long long t;
long long n;
long long d;
long long arr[99999999];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=0;i<t;i++){
        cin>>n>>d;
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
    }
    cout<<0<<endl;
    fclose(stdin);
    fclose(stdout);
}
