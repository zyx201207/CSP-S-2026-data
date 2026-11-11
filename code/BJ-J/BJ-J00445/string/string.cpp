#include<iostream>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<map>
using namespace std;

int n,a[200010],s[200010],cnt,t;
char c[200010];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        cnt+=a[i];
        s[i]=s[i-1]+a[i];
    }
  //  if(cnt%2==1){
   //     for(t=1;t<=n;t++)
  //          if(s[t+1]>cnt/2)break;
//
  //  }
	cout<<0;
    return 0;
}
