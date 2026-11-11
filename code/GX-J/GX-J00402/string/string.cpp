#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n,a[200005],l=0,r,cnt=0;
char c[200005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    string s="";
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i] >> c[i];
        s.append(a[i],c[i]);
    }
    //cout << s << endl;
    r=s.size()-1;
    while(l<=r){
        if(s[l]!=s[r])cnt++;
        l++,r--;
    }
    r=n;
    /*while(l<r){
        int q=max(a[l],a[r])-min(a[l],a[r]);

        if()
    }*/
    cout << cnt;
    return 0;
}
