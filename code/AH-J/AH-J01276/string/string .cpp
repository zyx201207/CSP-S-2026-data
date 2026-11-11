#include<bits/stdc++.h>
using namespace std;
struct Node{
	long long l;
	char cp;
};
stack<Node> s;
long long n,a[200005],len[200005],ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		cin>>c[i];
		len[i]+=len[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		if(len[i]<=len[n]/2){
			s.push({a[i],c[i]});
			continue;
		}
		if(len[i-1]>=len[n]/2+len[n]%2){
			Node tmp=s.top(); 
			while(tmp.l<=a[i]){
				a[i]-=tmp.l;
				if(c[i]!=tmp.cp) ans+=tmp.l;
				s.pop();
				if(s.empty()) break;
				tmp=s.top();
			}
			if(!s.empty()){
				s.top().l-=a[i];
				if(s.top().cp!=c[i]) ans+=a[i];
			}
			continue; 
		} 
		long long len1=len[n]/2-len[i-1],len2=len[i]-len[n]/2-len[n]%2;
		if(len1==len2)continue;
		if(len1>len2) s.push({len1-len2,c[i]});
		else{
			len2-=len1;
			Node tmp=s.top();
			while(tmp.l<=len2){
				len2-=tmp.l;
				if(c[i]!=tmp.cp) ans+=tmp.l;
				s.pop();
				if(s.empty()) break;
				tmp=s.top();
			}
			if(!s.empty()){
				s.top().l-=len2;
				if(s.top().cp!=c[i]) ans+=len2;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
