#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N=2e5+10;
struct node{
    int data;
    bool andw[31];
}a[N];
int sum[N];
vector<int> canbe;
bool cmp(int x,int y){
    return a[x].data>a[y].data;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].data;
        for(int j=30;j>=0;j--){
            if(((1<<j)&a[i].data)){
                sum[j]++;
                a[i].andw[j]=true;
            }
        }
    }
 //   for(int i=0;i<=30;i++){
 //       cout<<sum[i]<<' ';
 //   }
 //   cout<<'\n';
    int ans=2147483647,d=0;
    for(int num=30;num>=0;num--){
        if(sum[num]>=m){
            d=num;
            break;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i].andw[d]){
            canbe.push_back(i);
        }
    }
  //  cout<<d<<'\n';
 //   for(int i=0;i<canbe.size();i++){
 //       cout<<a[canbe[i]].data<<' '<<canbe[i]<<"     ";
 //   }
 //   cout<<'\n';
 //   cout<<"\n=================================\n";


  //  for(int i=1;i<=n;i++){
  //      for(int j=0;j<30;j++){
  //          cout<<a[i].andw[j]<<' ';
  //      }
  //      cout<<endl;
  //  }




 //   cout<<"\n=================================\n";
 //   cout<<"\n\n";
 //   cout<<"\n=================================\n";
    for(int j=d-1;j>=0;j--){
        vector<int> temp;
        int sum=0;
 //       for(int i=0;i<canbe.size();i++){
 //           cout<<a[canbe[i]].data<<' '<<canbe[i]<<"     ";
 //       }
 //       cout<<'\n';
        for(int i=0;i<canbe.size();i++){
            if(a[canbe[i]].andw[j]){
                temp.push_back(canbe[i]);
                sum++;
            }
        }
        if(sum>=m){
            canbe=temp;
        }
    }
//    cout<<"\n=================================\n";
    sort(canbe.begin(),canbe.end(),cmp);
    for(int i=0;i<m;i++){
        ans&=a[canbe[i]].data;
//        cout<<a[canbe[i]].data<<' ';
    }
//    cout<<'\n';
    cout<<ans;
    return 0;
}
