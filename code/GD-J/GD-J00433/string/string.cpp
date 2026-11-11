#include<iostream>
#include<queue>
using namespace std;
struct dot{
	char v;
	int cnt;
}a[200005];
int n;
long long len;
queue<dot>q;
dot l[200005],r[200005];
long long lm,rm;
int ln,rn;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].cnt>>a[i].v;
		len+=a[i].cnt;
	}
	if(len%2){
		while(lm+a[ln+1].cnt<=len/2){
			ln++;
			l[ln].cnt=a[ln].cnt;
			l[ln].v=a[ln].v;
			lm+=l[ln].cnt;
		}
		if(lm<len/2){
			ln++;
			l[ln].cnt=len/2-lm;
			l[ln].v=a[ln].v;
		}
		if(a[ln].cnt>l[ln].cnt+1){
			r[++rn].v=l[ln].v;
			r[rn].cnt=a[ln].cnt-l[ln].cnt-1;
			for(int i=ln+1;i<=n;i++){
				r[++rn].cnt=a[i].cnt;
				r[rn].v=a[i].v;
			}
		}
		else if(a[ln].cnt==l[ln].cnt+1){
			for(int i=ln+1;i<=n;i++){
				r[++rn].cnt=a[i].cnt;
				r[rn].v=a[i].v;
			}
		}
		else{
			r[++rn].v=a[ln+1].v;
			r[rn].cnt=a[ln+1].cnt-1;
			for(int i=ln+2;i<=n;i++){
				r[++rn].cnt=a[i].cnt;
				r[rn].v=a[i].v;
			}	
		}
		long long p=l[1].cnt;
		int rt=rn,lt=1;
		q.push(r[rt]);
		while(lt<=ln or rt>=1){
			char vt=q.front().v;int c=q.front().cnt;
			if(p==c){
				if(l[lt].v!=vt)ans+=c;
				lt++;
				p=l[lt].cnt;
				rt--;
				q.pop();
				q.push(r[rt]);
			}
			else if(p>c){
				if(l[lt].v!=vt)ans+=c;
				p-=c;
				rt--;
				q.pop();
				q.push(r[rt]);
			}
			else{
				if(l[lt].v!=vt)ans+=p;				
				lt++;
				q.pop();
				q.push({vt,c-p});
				p=l[lt].cnt;
			}
		}
		cout<<ans;
	}
	else{
		while(lm+a[ln+1].cnt<=len/2){
			ln++;
			l[ln].cnt=a[ln].cnt;
			l[ln].v=a[ln].v;
			lm+=l[ln].cnt;
		}
		if(lm<len/2){
			ln++;
			l[ln].cnt=len/2-lm;
			l[ln].v=a[ln].v;
		}
		if(a[ln].cnt>l[ln].cnt){
			r[++rn].v=l[ln].v;
			r[rn].cnt=a[ln].cnt-l[ln].cnt;
		}
		for(int i=ln+1;i<=n;i++){
			r[++rn].cnt=a[i].cnt;
			r[rn].v=a[i].v;
		}
		long long p=l[1].cnt;
		int rt=rn,lt=1;
		q.push(r[rt]);
		while(lt<=ln or rt>=1){
			char vt=q.front().v;int c=q.front().cnt;
			if(p==c){
				if(l[lt].v!=vt)ans+=c;
				lt++;
				p=l[lt].cnt;
				rt--;
				q.pop();
				q.push(r[rt]);
			}
			else if(p>c){
				if(l[lt].v!=vt)ans+=c;
				p-=c;
				rt--;
				q.pop();
				q.push(r[rt]);
			}
			else{
				if(l[lt].v!=vt)ans+=p;				
				lt++;
				q.pop();
				q.push({vt,c-p});
				p=l[lt].cnt;
			}
		}
		cout<<ans;
	}
	return 0;
} 
