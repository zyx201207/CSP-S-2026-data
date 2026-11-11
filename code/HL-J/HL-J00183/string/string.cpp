#include<bits/stdc++.h>
using namespace std;
struct aa{
    long long start;
    long long ed;
    long long si;
    char str;
}a[100010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long sumsi=0;
    for(int i=0;i<n;i++){
        a[i].start=sumsi;
        cin>>a[i].si;
        sumsi+=a[i].si;
        a[i].ed=sumsi;
        cin>>a[i].str;
    }
    long long flag=0;
    long long sum=0;
    long long l=0,r=n-1;
    long long ls=0,rs=sumsi;
    while(r>=0){
        if(a[l].str!=a[r].str){
            if((a[l].ed-ls)<(rs-a[r].start)){
                //<<"rb"<<endl;
                int z=(a[l].ed-ls);
                sum+=z;
                ls+=z;
                rs-=z;
                l++;
            }
            else if((a[l].ed-ls)>(rs-a[r].start)){
                //cout<<"lb"<<endl;
                int z=(rs-a[r].start);
                sum+=z;
                ls+=z;
                rs-=z;
                r--;
            }
            else if((a[l].ed-ls)==(rs-a[r].start)){
                //cout<<"the same"<<endl;
                int z=(rs-a[r].start);
                ls+=z;
                rs-=z;
                sum+=z;
                r--;
                l++;
            }
        }
        else{
            if((a[l].ed-ls)<(rs-a[r].start)){
                int z=(a[l].ed-ls);
                ls+=z;
                rs-=z;
                l++;
            }
            else if((a[l].ed-ls)>(rs-a[r].start)){
                int z=(rs-a[r].start);
                ls+=z;
                rs-=z;
                r--;
            }
            else{
                int z=(rs-a[r].start);
                ls+=z;
                rs-=z;
                r--;
                l++;
            }
        }
    }
    cout<<sum/2;
    return 0;
}
