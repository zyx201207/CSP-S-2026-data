#include<bits/stdc++.h>
using namespace std;
int a[10000],ak,num;
string s;
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int m;
	cin>>m;
	for(int i=1;i<=m;i++){
        int k;
        cin>>k>>s;
        if(a['a'-(s[0]-'0')-48]==0) ak++;
        a['a'-(s[0]-'0')-48]+=k;
        num+=k;
	}
    if(m==1){
        cout<<0;
        return 0;
    }
	sort(a,a+24);
	if(a[23]==num/ak){
        cout<<0;
        return 0;
	}
    return 0;
}
