//GZ-J00248 贵阳市南明区华麟学校 杨瑞泽 
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct Node{
	long long a;
	char s;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n; cin>>n;
    string h;
    for(int i=1;i<=n;i++){
    	cin>>a[i].a>>a[i].s;
    	for(int j=0;j<a[i].a;j++) h+=a[i].s;
	}
	h='0'+h;
	long long ans=0;
	for(int i=1,j=h.size()-1;i<=h.size()/2;i++,j--){
		if(h[i]-'a'!=h[j]-'a') ans++;
	}
	cout<<ans;
	return 0;
}
