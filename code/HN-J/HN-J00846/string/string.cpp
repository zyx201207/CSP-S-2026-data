#include<bits/stdc++.h>
using namespace std;
long long n,ans;
struct node{
	long long a;
	char c;
}sn[200050];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>sn[i].a>>sn[i].c;
	}
	int l=1,r=n;
	while(l<=r){
		if(sn[l].c!=sn[r].c){
			ans+=max(sn[l].a,sn[r].a);
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
} 
