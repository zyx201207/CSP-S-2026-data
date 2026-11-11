#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long a[N]={};
char b[N]={};
long long n;
long long sum=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    long long l=1;
    long long r=n;
    while(l<r){
        if(r-l==1&&b[r]!=b[l]){
            sum+=min(a[r],a[l]);
            //cout<<"finally pk!";
            break;
        }
        else if(r-l==1&&b[r]==b[l]){
            //cout<<"boom boom!!!!!";
            break;
        }
        else{
            if(a[l]>a[r]&&b[l]!=b[r]){
                //cout<<"a["<<l<<"]kill a["<<r<<"]";
                //cout<<endl;
                //cout<<"a["<<l<<"]="<<a[l]<<"a["<<r<<"]="<<a[r]<<endl;
                sum+=a[r];

                a[l]=a[l]-a[r];
                a[r]=0;
                //cout<<"a["<<l<<"]="<<a[l]<<"a["<<r<<"]="<<a[r]<<endl;
                r--;
                //cout<<"l="<<l<<" "<<"r--="<<r<<" ";
                //cout<<endl;
            }
            else if(a[l]==a[r]&&b[l]!=b[r]){
                //cout<<"a["<<l<<"]a["<<r<<"] p"<<endl;
                //cout<<"a["<<l<<"]="<<a[l]<<"a["<<r<<"]="<<a[r]<<endl;
                sum+=a[l];
                //cout<<"a["<<l<<"]="<<a[l]<<"a["<<r<<"]="<<a[r]<<endl;
                r--;
                l++;
                //cout<<"l++="<<l<<" "<<"r--="<<r<<" ";
                //cout<<endl;
            }
            else if(a[l]<a[r]&&b[l]!=b[r]){
                //cout<<"a["<<r<<"]kill a["<<l<<"]"<<endl;
                //cout<<"a["<<l<<"]="<<a[l]<<"a["<<r<<"]="<<a[r]<<endl;
                sum+=a[l];
                a[r]=a[r]-a[l];
                a[l]=0;
                //cout<<"a["<<l<<"]="<<a[l]<<"a["<<r<<"]="<<a[r]<<endl;
                l++;
                //cout<<"l++="<<l<<" "<<"r="<<r<<" ";
                //cout<<endl;
            }
            else if(a[r]>a[l]&&b[l]==b[r]){
                //cout<<"a["<<r<<"]kill a["<<l<<"]"<<endl;
                //cout<<"a["<<l<<"]="<<a[l]<<"a["<<r<<"]="<<a[r]<<endl;
                //cout<<"but b["<<l<<"]=b["<<r<<"]="<<b[l]<<" ";
                //cout<<endl;
                a[r]=a[r]-a[l];
                a[l]=0;
                //cout<<"a["<<l<<"]="<<a[l]<<"a["<<r<<"]="<<a[r]<<endl;
                l++;
                //cout<<"l++="<<l<<" "<<"r="<<r<<" ";
                //cout<<endl;
            }
            else if(a[l]>a[r]&&b[l]==b[r]){
                //cout<<"a["<<l<<"]kill a["<<l<<"]"<<endl;
                //cout<<"a["<<l<<"]="<<a[l]<<"a["<<r<<"]="<<a[r]<<endl;
                //cout<<"but b["<<l<<"]=b["<<r<<"]="<<b[l]<<" ";
                //cout<<endl;
                a[l]=a[l]-a[r];
                a[r]=0;
                //cout<<"a["<<l<<"]="<<a[l]<<"a["<<r<<"]="<<a[r]<<endl;
                r--;
                //cout<<"l="<<l<<" "<<"r--="<<r<<" ";
                //cout<<endl;
            }
            else{
                r--;
                l++;
                //cout<<"boom!!!";
            }
        }
    }
    cout<<sum;
    return 0;
}
