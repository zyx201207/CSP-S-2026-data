#include<bits/stdc++.h>
using namespace std;
long long lst[1000000][2];
long long lstt[1000000][2];
long long s;
long long num;
char x;
long long ans;
long long j;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>lst[i][1];
        s+=lst[i][1];
        cin>>x;
        lst[i][2]=x-'!';
        //cout<<lst[i][2]<<endl;
        if(lst[i][2]==lstt[num][2]){
            //cout<<"o1"<<endl;
            lstt[num][1]+=lst[i][1];
        }else{
            //cout<<"o2"<<endl;
            num++;
            lstt[num][1]+=lst[i][1];
            lstt[num][2]=lst[i][2];
        }
    }
    j=num;
    for(int i=1;i+num-j<=num;){
        //cout<<1;
        //cout<<" "<<lstt[i][1]<<" "<<lstt[i][2]<<"o3"<<endl;
        if(lstt[i][2]==lstt[j][2]){
            if(lstt[i][1]<lstt[j][1]){
                lstt[j][1]-=lstt[i][1];
                i++;
            }
            else if(lstt[i][1]>lstt[j][1]){
                lstt[i][1]-=lstt[j][1];
                j--;
            }
            else if(lstt[i][1]==lstt[j][1]){
                i++;
                j--;
            }
        }else{
            if(lstt[i][1]<lstt[j][1]){
                lstt[j][1]-=lstt[i][1];
                ans+=lstt[i][1];
                i++;
            }
            else if(lstt[i][1]>lstt[j][1]){
                lstt[i][1]-=lstt[j][1];
                ans+=lstt[j][1];
                j--;
            }
            else if(lstt[i][1]==lstt[j][1]){
                ans+=lstt[i][1];
                i++;
                j--;
            }
        }
        //for(int k=1;k<=num;k++){cout<<lstt[k][1]<<" "<<lstt[k][2]<<"o4"<<ans<<endl;}
    }
    cout<<ans;
    return 0;
}
