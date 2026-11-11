#include<bits/stdc++.h>
using namespace std;
const int large = 1e6+5;
int m,n;
int po[large];
int diff[large];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >>m>>n;
    int ccc,flag = 0;
    for(int i=1;i<=m;i++){
        cin >> po[i];

    }
    if(m > 5000){
        int cha = abs(po[2]-po[1]),sum;sum = cha;
        int ans=0;
        for(int i=1;;i++){
            if(n>=cha) n-=sum,ans++;
            else{cout <<min(ans,m);return 0;}
            sum+=cha;
        }

    }
    int ans = -214748,num = 0;
    for(int i=1;i<=m;i++){
        int cpow = n;
        for(int j=1;j<=m;j++) diff[j] = po[i]-po[j];
        sort(diff+1,diff+m+1);
        for(int j=1;j<=m;j++){
            if(cpow >= diff[j] && diff[j]>=0) cpow-=diff[j],num++;
            else if(cpow < diff[j])break;
            //cout <<cpow<<' '<<num<<"-----";
        }
        //cout <<endl;
        ans = max(num,ans);
        num = 0;
    }
    cout <<ans;
    return 0;
}
