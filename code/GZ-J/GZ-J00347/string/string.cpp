//GZ-J00347 赵思成 贵阳市南明区华麟学校 
#include<bits/stdc++.h>
using namespace std;
struct st{
	long long a;
	char c;
}s[1000005];
long long len=0,n,cnt=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
		len+=s[i].a;
	}long long j=1,k=n;
	long long i=1;
	while(i<=len/2){
		if(s[j].c!=s[k].c){
			if(s[j].a>s[k].a){
				cnt+=s[k].a;
				i+=s[k].a;
				s[j].a-=s[k].a;
				k--;
			}else{
				cnt+=s[j].a;
				i+=s[j].a;
				j++;
				s[k].a-=s[j].a;
			}
		}else{
			if(s[j].a>s[k].a){
				i+=s[k].a;
				k--;
				s[j].a-=s[k].a;
			}else{
				i+=s[j].a;
				j++;
				s[k].a-=s[j].a;
			}
		}
	}
	cout<<cnt;
	return 0;
}
