//GZ-J00301-观山湖区第八中学-金煜文
#include <bits/stdc++.h>
using namespace std;
int ans,sum;
long long asd[30];
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int t;
        char s;
        cin>>t>>s;
        if(s=='a') asd[1]++;
        if(s=='b') asd[2]++;
        if(s=='c') asd[3]++;
        if(s=='d') asd[4]++;
        if(s=='e') asd[5]++;
        if(s=='f') asd[6]++;
        if(s=='g') asd[7]++;
        if(s=='h') asd[8]++;
        if(s=='i') asd[9]++;
        if(s=='j') asd[10]++;
        if(s=='k') asd[11]++;
        if(s=='l') asd[12]++;
        if(s=='m') asd[13]++;
        if(s=='n') asd[14]++;
        if(s=='o') asd[15]++;
        if(s=='p') asd[16]++;
        if(s=='q') asd[17]++;
        if(s=='r') asd[18]++;
        if(s=='s') asd[19]++;
        if(s=='t') asd[20]++;
        if(s=='u') asd[21]++;
        if(s=='v') asd[22]++;
        if(s=='w') asd[23]++;
        if(s=='x') asd[24]++;
        if(s=='y') asd[25]++;
        if(s=='z') asd[26]++;
    }
    for(int i=1;i<=26;i++){
        if(asd[i]) sum++;
    }
    sort(asd+1,asd+27);
    if(sum==1){
        cout<<0;
        return 0;
    }
    for(int i=26-sum+1;i<=27-sum+sum/2;i++){
        ans+=asd[i];
    }
    cout<<ans;
    return 0;
}
