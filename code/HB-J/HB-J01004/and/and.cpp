#include <bits/stdc++.h>
using namespace std;
string a[200005];
int n,m;
string check(int x){
    string s,a;
    while(x>0){
        if(x%2==0){
            s.append("0");
        }
        else{
            s.append("1");
        }
        x/=2;
    }
    for(int i=s.size()-1;i>=0;i--){
        a.append(s.substr(i,1));
    }
    return a;
}
long long ad(string a,string b){
    long long sum=0;
    int i=a.size()-1;
    int j=b.size()-1;
    int n=0;
    while(j>=0){
        if(b[j]=='1'&&a[i]=='1'){
            sum+=pow(2,n);
        }
        n++;
        i--;
        j--;
    }
    return sum;
}
bool cmp(string x,string y){
    return x.size()>y.size();
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long t;
    cin>>n>>m;
    long long maxx=-1;
    for(int i=1;i<=n;i++){
        cin>>t;
        maxx=max(maxx,t);
        a[i]=check(t);
    }
    if(m==1){
        cout<<maxx;
        return 0;
    }
    sort(a+1,a+1+n,cmp);
    maxx=-1;
    if(m==2){
        for(int i=1;i<=n-m+1;i++){
            for(int j=i+1;j<=n;j++){
                maxx=max(maxx,ad(a[i],a[j]));
            }
        }
    }
    else if(m==3){
        for(int i=1;i<=n-m;i++){
            for(int j=i+1;j<=n-1;j++){
                for(int q=j+1;q<=n;q++){
                    maxx=max(maxx,ad(check(ad(a[i],a[j])),a[q]));
                }
            }
        }
    }
    else if(m==4){
        for(int i=1;i<=n-m-1;i++){
            for(int j=i+1;j<=n-2;j++){
                for(int q=j+1;q<=n-1;q++){
                        for(int w=q+1;w<=n;w++){
                            maxx=max(maxx,ad(check(ad(check(ad(a[i],a[j])),a[q])),a[w]));
                        }
                }
            }
        }
    }

    cout<<maxx;
    return 0;
}
