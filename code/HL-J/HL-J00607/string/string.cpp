#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
long long a,s[1000000],g=0,u=0;
char d[100000];
cin>>a;
for(long long y=0;y<a;y++){
    cin>>s[y]>>d[y];
u=u+s[y];
}
long long q;
if(a%2==0){
    q=a/2;

}else{
q=a/2+1;


}


for(long long i=0;i<q;i++){
    if(d[i]!=d[a-i-1]){
      g=g+max(s[i],s[a-i-1]);
    }




}

if(u/2==0 && d[q]%2==1){
 cout<<g+1;
}else if(u%2==1){
cout<<(g+1)/2+1;
}else{
cout<<g;
}

return 0;
freopen("string.out","w",stdout);
}
