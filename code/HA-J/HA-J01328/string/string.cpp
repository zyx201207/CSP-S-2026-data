#include<bits/stdc++.h>
#define endl '\n'
#define getchar getchar_unlocked
#define int unsigned long long
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
struct node{
	int a;
	char c;
}s[200005];
vector<node>l,r;
int n,cnt,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		s[i].a=read();
		scanf("%c",&s[i].c);
		cnt+=s[i].a;
	}
	bool flag=0;
	if(cnt%2!=0)flag=1;
	cnt/=2;
	long long sum=0,i;
	for(i=1;i<=n;i++)
		if(sum+s[i].a<=cnt){
			sum+=s[i].a;
			l.push_back({s[i].a,s[i].c});
		}
		else break;
	if(sum!=cnt){
		l.push_back({abs(sum-cnt),s[i].c});
		s[i].a-=abs(cnt-sum);
	}
	if(flag!=0)s[i].a--;
	for(int j=i;j<=n;j++)
		if(s[j].a!=0)
			r.push_back({s[j].a,s[j].c});
	reverse(r.begin(),r.end());
//	for(auto m:l)cout<<m.a<<" "<<m.c<<endl;
//	cout<<endl;
//	for(auto m:r)cout<<m.a<<" "<<m.c<<endl;
//	cout<<cnt<<endl;
//	for(int j=1;j<=n;j++)
//		cout<<s[j].a<<endl;
	int j,k;
	for(j=0,k=0;j<l.size()&&k<r.size();){
		if(l[j].c==r[k].c){
			if(l[j].a>r[k].a){
				l[j].a-=r[k].a;
				r[k].a=0;
				k++;
			}
			else if(l[j].a==r[k].a){
				l[j].a=0;
				r[k].a=0;
				j++;k++;
			}
			else{
				r[k].a-=l[j].a;
				l[j].a=0;
				j++;
			}
		}
		else{
			ans+=min(l[j].a,r[k].a);
			if(l[j].a>r[k].a){
				l[j].a-=r[k].a;
				r[k].a=0;
				k++;
			}
			else if(l[j].a==r[k].a){
				r[k].a=0;
				l[j].a=0;
				j++,k++;
			}
			else{
				r[k].a-=l[j].a;
				l[j].a=0;
				j++;
			}
		}
	}
	cout<<ans<<endl;
	return 0; 
}// 我 chovy , 你 出 題 給 我 出 好 了 啊 ！ T2 出 成 這 德 行 除 了 CCF 還 有 誰 

