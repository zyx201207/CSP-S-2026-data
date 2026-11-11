//GZ-J00394 姓名：周昊杨 学校：贵阳市第一中学 
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e5+5;
string s,s1; 
int n,cnt;
struct st{
	int m;
	char c;
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].m>>a[i].c;
		
	}
	int h=1,t=n;
	while(h<=t){
		if(a[h].m<a[t].m){
			if(a[h].c!=a[t].c){
				cnt+=a[h].m;
			}
			a[t].m-=a[h].m;
			h++;
		}
		else{
			if(a[h].c!=a[t].c){
				cnt+=a[t].m;
			}
			a[h].m-=a[t].m;
			t--;
		}
	}
	cout<<cnt;
	return 0;
}
