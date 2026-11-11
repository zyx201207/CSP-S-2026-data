#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+10;
long long n,t,w,y,ans=0,p;
struct p{
	long long a;
	char b;
}m[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i].a>>m[i].b;
	}
	p=n;
	for(int i=1;i<p;){
		if(m[i].b==m[p].b){
			t=min(m[i].a,m[p].a);
			w=max(m[i].a,m[p].a);
			y=w-t;
			if(m[i].a>m[p].a){
				m[i].a-=y;
				p--;
			}else if(m[i].a<m[p].a){
				m[p].a-=y;
				i++;
			}else{
				i++;
				p--;
			}
		}else{
			t=min(m[i].a,m[n-i+1].a);
			w=max(m[i].a,m[n-i+1].a);
			y=w-t;
			if(m[i].a>m[p].a){
				m[i].a-=y;
				ans+=m[p].a;
				p--;				
			}else if(m[i].a<m[p].a){
				m[p].a-=y;
				ans+=m[i].a;
				i++;
			}else{
				ans+=m[i].a;
				i++;
				p--;
			}				
		}
	}
	cout<<ans;	
	return 0;
} 
