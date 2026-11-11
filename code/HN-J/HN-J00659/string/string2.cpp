#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("string4.in","r",stdin);
    //freopen("string.out","w",stdout);
    int n;cin>>n;
    vector<int>a(n+1);
    vector<char>c(n+1);
    long long totaa=0;
    for(int i=1;i<=n;i++) {
        cin>>a[i]>>c[i];
        totaa+=a[i];
    }
    long long mid=(totaa-1)/2+1;
    vector<int>a1;
    vector<char>c1;
    vector<int>a2;
    vector<char>c2;
    long long tota=0;
    bool flag=0;
    for(int i=1;i<=n;i++) {
        tota+=a[i];
        if(i==1000||i==1001)cout<<tota+a[i-1]<<'\n';

        if(totaa%2==1&&tota+a[i-1]>=mid||totaa%2==0&&tota>=mid){
            if(!flag) {
                cout<<i<<'\n';
                if(totaa%2==1) tota+=a[i-1];
                int s=tota-mid;
                cout<<tota<<' '<<totaa<<' '<<mid<<'\n';
                cout<<s<<' '<<a[i]<<c[i]<<'\n';
                if(totaa%2==1) {
                    a1.push_back(a[i]-s);
                    c1.push_back(c[i]);
                    a2.push_back(s);
                } else {
                    a2.push_back(a[i]-s);
                }
                c2.push_back(c[i]);
                flag=1;
                continue;
            }
            a1.push_back(a[i]);
            c1.push_back(c[i]);
            a2.push_back(a[n-i+1]);
            c2.push_back(c[n-i+1]);
        }
    }

    for(int i=0;i<2;i++) {
        cout<<a1[i]<<c1[i]<<'\n';
    }
    //cout<<'\n';
    for(int i=0;i<2;i++) {
        cout<<a2[i]<<c2[i]<<'\n';
    }

    int j=0;
    long long ans=0;
    int i=0;
    while(i<a1.size()&&j<a2.size()) {
        if(c1[i]==c2[j]) {
            if(a1[i]>a2[j]) {
                //cout<<"a1[i]>a2[j],ans+="<<0<<" 1:"<<a1[i]<<c1[i]<<" 2:"<<a2[j]<<c2[j]<<'\n';
                a1[i]=a1[i]-a2[j];
                a2[j]=0;
                //cout<<"a1[i]>a2[j],ans+="<<0<<" 1:"<<a1[i]<<c1[i]<<" 2:"<<a2[j]<<c2[j]<<'\n';
            }
            else {
                //cout<<"a1[i]<a2[j],ans+="<<0<<" 1:"<<a1[i]<<c1[i]<<" 2:"<<a2[j]<<c2[j]<<'\n';
                a2[j]=a2[j]-a1[i];
                a1[i]=0;
                //cout<<"a1[i]<a2[j],ans+="<<0<<" 1:"<<a1[i]<<c1[i]<<" 2:"<<a2[j]<<c2[j]<<'\n';
            }
        } else {
            if(a1[i]>a2[j]) {
                //cout<<"a1[i]>a2[j],ans+="<<a2[j]<<" 1:"<<a1[i]<<c1[i]<<" 2:"<<a2[j]<<c2[j]<<'\n';
                ans+=a2[j];
                a1[i]=a1[i]-a2[j];
                a2[j]=0;
                //cout<<"a1[i]>a2[j],ans+="<<a2[j]<<" 1:"<<a1[i]<<c1[i]<<" 2:"<<a2[j]<<c2[j]<<'\n';
            }
            else {
                //cout<<"a1[i]<a2[j],ans+="<<a1[i]<<" 1:"<<a1[i]<<c1[i]<<" 2:"<<a2[j]<<c2[j]<<'\n';
                ans+=a1[i];
                a2[j]=a2[j]-a1[i];
                a1[i]=0;
                //cout<<"a1[i]<a2[j],ans+="<<a1[i]<<" 1:"<<a1[i]<<c1[i]<<" 2:"<<a2[j]<<c2[j]<<'\n';
            }
        }
        if(a1[i]==0){
            //cout<<"i++\n";
            i++;
        }
        if(a2[j]==0){
            //cout<<"j++\n";
            j++;
        }
    }
    cout<<ans;
    /*
    long long shengyu=0;
    long long ans=0;
    bool flag=0;
    for(int i=1;i<=n;i++) {
        tota+=a[i];
        if(!flag&&tota>=mid){
            flag=1;

        }

    }
    */
}
