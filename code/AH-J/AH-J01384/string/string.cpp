#include<bits/stdc++.h>
using namespace std;
long long n;
long long x;
string a;
string b;
int w(int cnt){
    long long l=0,r=cnt-1;
    long long s=0;
    while(l<=r){
        if(b[l]!=b[r]){
            s++;
        }
        l++;
        r--;
    }
    return s;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
	cin>>n;
	long long cnt=0;
	while(n--){
        cin>>x>>a;
        for(long long i=1;i<=x;i++){
            b+=a;
            cnt++;
        }
	}
	cout<<w(cnt);
	return 0;
}
