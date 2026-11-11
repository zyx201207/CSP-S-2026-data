//GZ-J00557 贵阳市南明区第一实验中学 夏泽轩
#include<bits/stdc++.h>
using namespace std;
long long pos=1,ans;
int n,k,mid,b;
char c;
int lcount(vector<vector<int>>&str,int l,int r,int letter){
    int cnt=0;
    for(int i=b;i<n;i++){
        if(str[i][1]<l)
            continue;
        if(str[i][0]>r)
            return cnt;
        if(str[i][0]<=l&&str[i][1]>=r)
            return str[i][2]==letter?r-l+1:0;
        if(str[i][0]>=l&&str[i][1]<=r)
            if(str[i][2]==letter)
                cnt+=str[i][1]-str[i][0]+1;
        else if(str[i][0]<l&&str[i][1]>=r)
            if(str[i][2]==letter)
                cnt+=str[i][1]-l+1;
        else if(str[i][0]>=l&&str[i][1]>=r)
            return str[i][2]==letter?cnt+r-str[i][0]+1:cnt;
    }
    return cnt;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    vector<vector<int>>str(n,vector<int>(3));
    for(int i=0;i<n;i++){
        cin>>k>>c;
        str[i][0]=pos;
        pos+=k;
        str[i][1]=pos-1;
        str[i][2]=c-'a';
    }
    int mid=pos/2;
    for(int i=0;i<n;i++){
        if(str[i][0]<=mid&&str[i][1]>=mid){
            b=i;
            break;
        }
    }
    k=0;
    while(str[k][1]<mid){
        ans+=lcount(str,pos-str[k][1],pos-str[k][0],str[k][2]);
        k++;
        cout<<k<<endl;
    }
    if(str[k][0]<mid)ans+=lcount(str,pos-mid+1,pos-str[k][0],str[k][2]);
    cout<<(pos-1)/2-ans;
    return 0;
}
