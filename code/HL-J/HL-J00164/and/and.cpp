#include<bits/stdc++.h>
using namespace std;
string yu(int x){
    string sum;
    while(x!=0){
        int y=x%2;
        sum = to_string(y) + sum;
        x/=2;
    }
    return sum;
}
string andd(int x,int y){
    string s1 = yu(x);
    string s2 = yu(y);
    int num1=s1.size();
    int num2=s2.size();
    int c = abs(num1-num2);
    int d = min(num1,num2);
    for(int i=0;i<d;i++){
        if(num1 < num2){
            if(s1[i]==s2[i+c]){
                s1[i]='1';
            }else{
                s1[i]='0';
            }
        }if(num1 > num2){
            if(s2[i]==s1[i+c]){
                s2[i]='1';
            }else{
                s2[i]='0';
            }
        }
    }
    if(num1 < num2){
        return s1;
    }else{
        return s2;
    }
}
const int N = 2e5+10;
int n,m,mx,a[N];
long long b[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<=15;i++){
        b[i] = pow(2,i);
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=(mx,a[i]);
    }
    if(m==1){
        cout << mx;
        return 0;
    }
    if(m==2){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                string ss = andd(a[i],a[j]);
                int num = stoi(ss);
                mx = max(mx,num);
            }
        }
        int sum=0;
        string sx = to_string(mx);
        int mm = sx.size();
        for(int i=0;i<mm;i++){
            sum += (sx[i]-'0')*b[mm-1-i];
        }
        cout << sum;
        return 0;
    }
    return 0;
}
