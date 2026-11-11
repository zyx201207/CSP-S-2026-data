#include<bits/stdc++.h>
using namespace std;
int n,cnt;
long long t1[100005],ans;
struct hw{
	int a;
	char c;
}m[100005];
char t[100005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i].a>>m[i].c;
		if(m[i].c!=m[i-1].c){
			t[++cnt]=m[i].c;
			t1[cnt]+=m[i].a;
		}
		else if(m[i].c==m[i-1].c){
			t1[cnt]+=m[i].a;
		}
	}
	if(cnt==1){
		cout<<0;
		return 0;
	}
	if(cnt%2==1){
		for(int i=1;i<=cnt/2;i++){
			if(t[i]==t[n-i+1]){
				ans+=abs(t1[i]-t1[cnt-i+1]);
			}
			else{
				ans+=max(t1[i],t1[cnt-i+1]);
			}
		}
	}
	else{
		for(int i=1;i<=cnt/2;i++){
			if(t[i]==t[n-i+1]){
				ans+=abs(t1[i]-t1[cnt-i+1]);
			}
			else{
				ans+=min(t1[i],t1[cnt-i+1]);
			}
		}
	}
	cout<<ans;
	return 0;
}
