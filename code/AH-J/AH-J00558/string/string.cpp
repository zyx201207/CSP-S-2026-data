//Trick||Treat!
#include<bits/stdc++.h>
using namespace std;
int main(){
//freopen("string.in", "r",stdin);
//freopen("string.out", "w",stdout);
string s,s1;
long long n,temp=0;char c;
cin>>n;
for(long long i=0;i<n;i++){
    temp=0;
    cin>>temp;
    cin>>c;
    for(long long j=0;j<temp;j++){
        s.push_back(c);
    }
}

n=0;
bool b=0;

for(int i=0;i<s.size();i++){
        b=0;
if(s[i]!=s[s.size()-i-1]){
    b=1;
}
if(b==1){
    s[s.size()-i-1]=s[i];
    n++;
}
}

cout<<n<<endl;

    return 0;
}
