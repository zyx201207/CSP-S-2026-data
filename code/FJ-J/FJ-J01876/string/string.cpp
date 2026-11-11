#include<bits/stdc++.h>
using namespace std;
long long n,sum=0,ans=0;
struct stu{
	long long a;
	char x;
}s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].x;
		sum+=s[i].a;
	}
	long long sum1=sum/2;
	long long cnt=0;
	long long id=1;
	for(int i=n;i>=1;i--){
		if(cnt+s[i].a<=sum1){
			cnt+=s[i].a;
			if(s[i].a>=s[id].a){
				if(s[i].x!=s[id].x){
					ans+=s[id].a;
				}
				s[i].a-=s[id].a;
				while(1){
					id++;
					if(s[i].a>=s[id].a){
						if(s[i].x!=s[id].x){
							ans+=s[id].a;
						}
						s[i].a-=s[id].a;
					}else{
						if(s[i].x!=s[id].x){
							ans+=s[i].a;
							s[id].a-=s[i].a;
						}
						break;
					}
				}
			}else{
				if(s[i].x!=s[id].x){
					ans+=s[i].a;
					s[id].a-=s[i].a;
				}
				while(1){
					i--;
					if(cnt+s[i].a<=sum1){
						cnt+=s[i].a;
					}else{
						s[i].a=sum1-cnt;
					}
					if(s[i].a<=s[id].a){
						if(s[i].x!=s[id].x){
							ans+=s[i].a;
							s[id].a-=s[i].a;
						}
					}else{
						if(s[i].x!=s[id].x){
							ans+=s[id].a;
							s[i].a-=s[id].a;
							id++;
						}
						break;
					}
				}
			}
		}else{
			long long q=sum1-cnt;
			while(1){
				if(s[id].a>=q){
					if(s[id].x!=s[i].x){
						ans+=q;
					}
					break;
				}else{
					if(s[id].x!=s[i].x){
						ans+=s[id].a;
						q-=s[id].a;
						id++;
					}
				}
			}
			break;
		}
	}
	cout<<ans;
	return 0;
}
