#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,sum,m[200005],sum2,pos,k;
char tmp[200005];
struct node{int x;char c;}l[200005],r[200005];
bool flag;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i]>>tmp[i];
		sum+=m[i];
	}for(int i=1;i<=n;i++){
		sum2+=m[i];
		if(flag) r[++pos].x=m[i],r[pos].c=tmp[i];
		else{
			if(sum2>sum/2){
				l[++pos].x=sum/2-sum2+m[i],l[pos].c=tmp[i];
				if(l[pos].x==0) pos--;
				r[1].x=sum2-sum/2-sum%2,r[1].c=tmp[i];
				k=pos,pos=1,flag=1;
			}else l[++pos].x=m[i],l[pos].c=tmp[i];
		}
	}int pos1=k,pos2=1,ans=0;
	while(pos1!=0||pos2!=pos+1){
		if(l[pos1].x>r[pos2].x){
			if(l[pos1].c==r[pos2].c) l[pos1].x-=r[pos2].x,pos2++;
			else ans+=r[pos2].x,l[pos1].x-=r[pos2].x,pos2++;
		}else if(l[pos1].x<r[pos2].x){
			if(l[pos1].c==r[pos2].c) r[pos2].x-=l[pos1].x,pos1--;
			else ans+=l[pos1].x,r[pos2].x-=l[pos1].x,pos1--;
		}else{
			if(l[pos1].c==r[pos2].c) pos1--,pos2++;
			else ans+=l[pos1].x,pos1--,pos2++;
		}
	}cout<<ans;
	return 0;
}
