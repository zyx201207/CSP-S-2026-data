#include <bits/stdc++.h>
using namespace std;
string s,b;
long long n,m,cnt;
char a,c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m>>a;
        for(int j=0;j<m;j++){
            b+=a;
        }
    }
    int len=b.size();
    if(len%2==0){
        int k=len-1;
        for(int i=0;i<len/2;i++){
			if(b[i]!=b[k]) cout<<1;
			k--;
        }
    }else{
    	int k=len-1;
        for(int i=0;i<=len/2;i++){
			if(b[i]!=b[k]) cnt++;
			k--;
        }
	}
    cout<<cnt;
}

