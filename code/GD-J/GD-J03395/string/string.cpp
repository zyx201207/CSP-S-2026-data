#include<bits/stdc++.h>
using namespace std;
struct node{
	char a;
	int num;
}m[200010];
long long h[2000];
vector<long long> s;
vector<char> k;
long long ans=0,top,e;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i].num>>m[i].a;
		sum+=m[i].num;
	}
	if(sum%2==0){
		long long maxn=0;
		for(int i=1;i<=n;i++){
			h[m[i].a]+=m[i].num;
			maxn=max(maxn,h[m[i].a]);
		}
		cout<<sum-maxn;
	}else{
		char t=' ';
		for(int i=1;i<=n;i++){
			if(m[i].a==t){
				s[s.size()-1]+=m[i].num;
			}else if(m[i].a!=t){
				t=m[i].a;
				s.push_back(m[i].num);
				k.push_back(m[i].a);
			}
		}
		e=s.size()-1,top=0;
		while(top<e){
			if(k[top]==k[e]){
				if(s[top]<s[e]){
					s[e]-=s[top];
					top++;
				}else if(s[top]>s[e]){
					s[top]-=s[e];
					e--;
				}else{
					top++;
					e--;
				}
			}else if(k[top]!=k[e]){
				if(s[top]<s[e]){
					s[e]-=s[top];
					ans+=s[top];
					top++;
				}else if(s[top]>s[e]){
					s[top]-=s[e];
					ans+=s[e];
					e--;
				}else{
					ans+=s[top];
					e--;
					top++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

