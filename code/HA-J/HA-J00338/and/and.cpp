#include<bits/stdc++.h>
using namespace std;
string s[20005];
bool cmp(string a1,string a2){
	if(a1>a2){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s[i];
	}
	sort(s,s+n,cmp);
	cout<<s[0];
	return 0;
}
