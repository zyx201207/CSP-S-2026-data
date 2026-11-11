#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,jsc,s[N],lcnt,rcnt;
int ans;
struct Node{
	int l;
	char z;
}a[N],pdl[N],pdr[N],cjjsq;
int sl[N],sr[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].z;
		jsc+=a[i].l;
		s[i]=s[i-1]+a[i].l;
	}
	int js2=jsc/2,cnt=0;
	if(jsc%2==1){
		js2++;
		while(s[cnt]<js2) cnt++;
		pdl[++lcnt].z=a[cnt].z;
		pdl[lcnt].l=js2-s[cnt-1];
		for(int i=cnt-1;i>=1;i--)
			pdl[++lcnt]=a[i];
		
		pdr[++rcnt].z=a[cnt].z;
		pdr[rcnt].l=s[cnt]+1-js2;
		for(int i=cnt+1;i<=n;i++)
			pdr[++rcnt]=a[i];
		
		for(int i=1;i<=lcnt;i++) sl[i]=sl[i-1]+pdl[i].l;
		for(int i=1;i<=rcnt;i++) sr[i]=sr[i-1]+pdr[i].l;
	}else{
		while(s[cnt]<js2) cnt++;
		pdl[++lcnt].z=a[cnt].z;
		pdl[lcnt].l=js2-s[cnt-1];
		for(int i=cnt-1;i>=1;i--)
			pdl[++lcnt]=a[i];
		js2++;
		if(s[cnt]<js2) cnt++;
		
		pdr[++rcnt].z=a[cnt].z;
		pdr[rcnt].l=s[cnt]+1-js2;
		for(int i=cnt+1;i<=n;i++)
			pdr[++rcnt]=a[i];
		
		for(int i=1;i<=lcnt;i++) sl[i]=sl[i-1]+pdl[i].l;
		for(int i=1;i<=rcnt;i++) sr[i]=sr[i-1]+pdr[i].l;
	}
	int ltot=1,rtot=0;
	for(int i=1;i<=lcnt;i++){
		ltot++;
		if(sl[ltot]<=sr[rtot]){
			if(pdr[rtot].z!=pdl[ltot].z) ans+=pdl[ltot].l;
			cjjsq.l-=pdl[ltot].l;
		}else{
			if(cjjsq.z!=pdl[ltot].z) ans+=cjjsq.l;
		}
		while(sr[rtot]<=sl[ltot]){
			rtot++;
			if(sr[rtot]<=sl[ltot]){
				if(pdr[rtot].z!=pdl[ltot].z) ans+=pdr[rtot].l;
			}else{
				
				if(pdr[rtot].z!=pdl[ltot].z){
					ans+=sl[ltot]-sr[rtot-1];
				}
				cjjsq.z=pdr[rtot].z;
				cjjsq.l=pdr[rtot].l-(sl[ltot]-sr[rtot-1]);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
//男孩的10.31：补习班，男人的10.31：出去玩，神的10.31：66CCFF
//哦对了我是神人，我只有神的一半CCF
//明年直接展示100+100+310+560=1070购买力
//天依等我明年中考完
//6767
//13*13=78+91=13*(6+7)





//没人觉得T.A.O.很好听吗
