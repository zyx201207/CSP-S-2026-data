#include<bits/stdc++.h>
using namespace std;

int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
int n,m;
cin>>n>>m;
char v[500005];

int a[500005];

for(int i=1;i<=n;i++)cin>>v[i];
for(int i=1;i<=m;i++){

        string s="$";
    for(int j=i;j<=n;j++){
            int l=0;
        if(s.find(v[j])>=1){
                s+=v[j];
    l++;
        }
else{
    s.erase(s.find(v[j]+1),l);
    l=s.find(v[j]);
}
    }
   for(int i=1;i<=m;i++){
    if(s.find(v[i])>=0)a[i]=i;
   }

}

for(char i=1;i<=m;i++)cout<<a[i]<<" ";
return 0;
}
