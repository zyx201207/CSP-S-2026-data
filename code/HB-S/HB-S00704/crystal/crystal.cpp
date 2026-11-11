#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],ans;
struct node{
long long val,num;
};
vector<node>e;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++)cin>>a[i];
sort(a+1,a+1+n);
long long v=a[1],cnt=1;
for(int i=2;i<=n;i++){
  if(a[i]!=v){
  e.push_back({v,cnt});
  v=a[i];
  cnt=1;
  continue;
  }
  cnt++;
}
for(int i=e.size()-1;i>0;i--){
long long s=m;
long long res=e[i].num;
int k=1;
while(s){
long long dis=e[i].val-e[i-k].val;
if(s>=dis){
	if(i-k<0)break;
    if(s<dis*e[i-k].num){res+=s/dis;break;}
    if(s>=dis*e[i-k].num){res+=e[i-k].num;s-=dis*e[i-k].num;}
    k++;
    }else{
		break;
	}
 } 
  ans=max(ans,res);
}
cout<<ans;
  return 0;
}
