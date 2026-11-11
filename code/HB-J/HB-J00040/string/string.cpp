#include <bits/stdc++.h>
using namespace std;
struct ac{
    long long shuz;
    char zf;
};

int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
long long n;
cin >> n;
vector<ac> a(n);
map<char,int> mp;
for(int i=0;i<n;i++){
    cin >> a[i].shuz >> a[i].zf;
    mp[a[i].zf]++;
}
if(n==1){
    cout<< 0;
    return 0;
}
int len=mp.size();
long long num=0,cnt=0;
for(int i=1;i<n;i++){
    if(a[i].zf==a[i-1].zf)num++;
    if(a[i].shuz==a[i-1].shuz)cnt++;
}
long long sum=0;
for(int i=1;i<len;i++){
    if(mp[i]==mp[i-1])sum++;
}
if(num==n){
    cout << 0;
    return 0;
}
else{
    num=0;
    if(sum+1==len&&cnt+1==n){
        cout << (n-n/len)*a[0].shuz;
        return 0;
    }
    if(n==2){
        int x=0;
        x=min(a[0].shuz,a[1].shuz);
        cout << x;
        return 0;
    }
    if(n%2==1&&cnt+1==n){
        for(int i=0;i<n/2;i++){
            if(a[i].zf!=a[n-1-i].zf){
                num+=a[i].shuz;
            }
        }
    }
    else if(n%2==1&&cnt+1!=n){
        for(int i=0;i<n/2;i++){
            if(i!=0){
                if(a[i].zf==a[i-1].zf){
                    a[i].shuz+=a[i-1].shuz;
                }
                if(a[n-1-i].zf==a[n-i].zf){
                    a[n-1-i].shuz+=a[n-i].shuz;
                }
            }
            if(a[i].zf==a[n-1-i].zf){
                if(a[i].shuz!=a[n-1-i].shuz){
                    num+=abs(a[i].shuz-a[n-1-i].shuz);
                    a[i+1].shuz++;
                }
            }
            else{
                if(a[i].shuz==a[n-1-i].shuz){
                    num+=a[n-1-i].shuz;
                }
                else{
                    int x=0;
                    x=min(a[i].shuz,a[n-1-i].shuz);
                    num+=x;
                    if(x==a[i].shuz){
                        a[n-1-i].shuz-=x;
                    }
                    else{
                        a[i].shuz-=x;
                    }
                    num++;


                }
            }
        }
    }
    else{
        for(int i=0;i<n/2-1;i++){
            if(i!=0){
                if(a[i].zf==a[i-1].zf){
                    a[i].shuz+=a[i-1].shuz;
                }
                if(a[n-1-i].zf==a[n-i].zf){
                    a[n-1-i].shuz+=a[n-i].shuz;
                }
            }
            if(a[i].zf==a[n-1-i].zf){
                if(a[i].shuz!=a[n-1-i].shuz){
                    num+=abs(a[i].shuz-a[n-1-i].shuz);
                    a[i+1].shuz++;
                }
            }
            else{
                if(a[i].shuz==a[n-1-i].shuz){
                    num+=a[n-1-i].shuz;
                }
                else{
                    int x=0;
                    x=min(a[i].shuz,a[n-1-i].shuz);
                    num+=x;
                    if(x==a[i].shuz){
                        a[n-1-i].shuz-=x;
                    }
                    else{
                        a[i].shuz-=x;
                    }
                    num++;

        }
            }


}
    }
}
cout <<num;
return 0;
}

