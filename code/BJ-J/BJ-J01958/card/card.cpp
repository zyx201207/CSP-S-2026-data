#include<iostream>
#include<string>
using namespace std;

long long n,m,a[500001],sum[500001];
string b;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            b+=a[j];
            if(b.find(a[j])!=j){
                b.erase(b.find(a[j]),b.find_last_of(a[j]));
            }
        }
        for(int j2=0;j2<b.size();j2++){
            sum[b[j2]++;
        }
    }
    for(int i=0;i<m;i++){
        cout<<sum[i]<<" ";
    }

    return 0;
}
