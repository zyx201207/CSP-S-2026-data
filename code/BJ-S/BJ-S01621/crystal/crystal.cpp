#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
string s;
LL n,sum;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","r",stdout);
	cin>>s>>n;
	for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            char c=s[i-1];
            int j=i;
            LL x=0;
            while(j<s.size()&&isdigit(s[i])){
                x=x*10+s[j]-'0';
                j++;
            }
            i=j-1;
            sum+=x;
        }
	}
	n%=sum;
	n++;
	for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            char c=s[i-1];
            int j=i;
            LL x=0;
            while(j<s.size()&&isdigit(s[i])){
                x=x*10+s[j]-'0';
                j++;
            }
            i=j-1;  
            if(n<=x){
            cout<<c<<endl;
            return 0;
            }else{
            n-=x;
            }
        }
	}
	return 0;
}