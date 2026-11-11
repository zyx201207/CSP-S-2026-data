#include <iostream>
using namespace std;
struct shu{
    long long ans,xu;
    char zi;
};
shu a[100005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int f=1,z=1;
    cin>>a[0].ans>>a[0].zi;

    for(int i=1;i<n;i++){
        cin>>a[f].ans>>a[f].zi;
        if(a[f].zi==a[f-1].zi){
            a[f-1].ans+=a[f].ans;
        }
        else{
            f++;
            z++;
        }

    }
    long long x=0;
    if(a[0].zi==a[1].zi){
        cout<<0;
    }
    else{

        for(int i=0;i<z;i++){
            x+=a[i].ans;
        }
        if(x%2==0){
            cout<<x/2;
        }
        else{
            cout<<(x-1)/2;
        }
    }
}
