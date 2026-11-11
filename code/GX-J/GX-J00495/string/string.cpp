#include<bits/stdc++.h>
using namespace std;
const int N=200000000000005;
char S[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long sum=0;
    while(n--){
        int a;
        char c;
        cin>>a>>c;
        while(a--){
            S[sum]=c;
            sum++;
        }
    }
    long long mid=(sum%2==0?sum/2:sum/2+1);
    long long left=mid-1,right=(sum%2==1?mid:mid+1);
    long long num=0;
    while(left){
        cout<<left<<" "<<right<<endl;
        cout<<S[left]<<" "<<S[right]<<endl;
        cout<<S[left]<<" "<<S[right]<<" "<<(S[left]!=S[right])<<endl;
        if(S[left]!=S[right]) num++;
        left--;
        right++;
    }
    cout<<num;
    return 0;
}
