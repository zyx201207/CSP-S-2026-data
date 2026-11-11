#include<bits/stdc++.h>
using namespace std;
//struct stu{
//	int a;
//	char c;
//};
//stu sz[200005];
string str;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	int n, i, j, cnt=0, t=0, ans=0, now=0;
	long long n, i, j, a, ans=0;
	char c;
	cin>>n;
	for(i=0;i<n;i++){
//		cin>>sz[i].a>>sz[i].c;
        cin>>a>>c;
        for(j=0;j<a;j++){
            str+=c;
        }
	}
    for(i=0;i<str.size()/2;i++){
        if(str[i]!=str[str.size()-1-i]){
            ans++;
        }
    }
    cout<<ans;
	return 0;
}
