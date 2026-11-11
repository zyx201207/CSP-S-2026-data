#include <bits/stdc++.h>
using namespace std;
/*思路 有一个左指针l 一个右指针l 指针指的一直是字段号
有一个lcnt rcnt分别是左、右边的计数（字符）（右边的只统计完整的）  这个是long long 
还有一个额外的e 表示当前字串还剩下多少可以用（如果有的话） 
然后l为大 r尝试减1 如果rcnt+ar以后 没超 就直接加在ans
如果超了 就改部分 并且rcnt+
*/ 
const int N=200005;
char c[N+5];
int l,r,n,a[N+5];
long long lcnt=0,rcnt=0,ecnt=0,sum=0,ans=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++) sum+=a[i];
	l=0,r=n;
	while(lcnt+rcnt<sum){
		if(lcnt+rcnt+ecnt==sum-1) break; 
		l++;
		if(l==r) break;
		//cout<<"现在考虑l=="<<l<<endl;
		//cout<<"r=="<<r<<endl;
		lcnt+=a[l];
		//这时候r有两种情况：r已经处理完上一整个字段和 和 r这个字段还有剩余
		if(ecnt>0){//还有剩的 
			if(rcnt+a[r]<lcnt){//剩下的得全用了 
				if(c[r]!=c[l]) ans+=(a[r]-ecnt);
				ecnt=0;
				rcnt+=a[r];
				//cout<<"		"<<r<<" 剩下的得全用了  "<<ans<<endl;
				r--;
			}
			else if(rcnt+a[r]==lcnt){//剩下的刚好给他全用完 
				if(c[r]!=c[l]) ans+=(a[r]-ecnt);
				ecnt=0;
				rcnt+=a[r];
				//cout<<"		"<<r<<" ecnt!=0且剩下的刚好给他全用完 "<<ans<<endl;
				r--;
				continue;
			}
			else if(rcnt+a[r]>lcnt){
				//还是拿一部分给它
				if(c[r]!=c[l]) ans+=lcnt-rcnt-ecnt;
				ecnt=lcnt-rcnt;
				//cout<<"		"<<r<<" 现在这一个r要挑一点改  "<<ans<<endl;
			}
		} 
		if(ecnt==0){//处理完 
			if(l==r) break;
			while(rcnt+a[r]<lcnt){
				if(c[r]!=c[l]) ans+=a[r];
				rcnt+=a[r];
				//cout<<"		"<<r<<" 把加上不会结束的加上 r=="<<r<<"  "<<ans<<endl;
				r--;
			}//把加上不会结束的加上 
			if(rcnt+a[r]==lcnt){//再刚好加一个 
				if(c[r]!=c[l]) ans+=a[r];
				rcnt+=a[r];
				//cout<<"		"<<r<<" ecnt==0 且再刚好加一个  "<<ans<<endl;
				r--;
				continue;
			}
			if(l==r) break;
			//现在这一个r要挑一点改
			ecnt=lcnt-rcnt;
			if(c[r]!=c[l]) ans+=ecnt;
			//cout<<"		"<<r<<" 现在这一个r要挑一点改  "<<ans<<endl;
		}
	}
	cout<<ans;
	return 0;
}
