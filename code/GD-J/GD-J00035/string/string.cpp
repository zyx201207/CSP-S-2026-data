#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans,len;
char c[200005];
struct node{
	long long x;
	char s;
};
queue<node> q;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	long long len1=len/2,len2=len/2;
	for(int i=1;i<=n;i++){
		if(a[i]>=len1){
			q.push({len1,c[i]});
			break;
		}
		else{
			len1-=a[i];
			q.push({a[i],c[i]});
		}
	}
	for(int i=n;i>=1;i--){
		if(a[i]>=len2){
			while(len2>=q.front().x&&!q.empty()){
				if(c[i]!=q.front().s){
					ans+=q.front().x;
				}
				len2-=q.front().x;
				q.pop();
			}
			if(q.front().s!=c[i]){
				ans+=len2;
			}
			q.front().x-=len2;
			break;
		}
		else{
			len2-=a[i];
			while(a[i]>=q.front().x&&!q.empty()){
				if(c[i]!=q.front().s){
					ans+=q.front().x;
				}
				a[i]-=q.front().x;
				q.pop();
			}
			if(q.front().s!=c[i]){
				ans+=a[i];
			}
			q.front().x-=a[i];
		}
	}
	printf("%lld\n",ans);
	return 0;
}
