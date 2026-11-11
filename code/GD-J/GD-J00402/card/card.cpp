#include<bits/stdc++.h>
using namespace std;
int b[500005];
int a[500005],d[500005],cnt[500005],lst[500005];
int c[500005],nxt[500005],fir[500005],p[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	bool f=0;
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		if(!fir[a[i]]) fir[a[i]]=i;
		c[a[i]]++;
		if(a[i]<a[i-1]){
			f=1;
		}
		d[a[i]]=i;
	}
	for(int i=1; i<=n; i++){
		lst[i]=p[a[i]];
		p[a[i]]=i;
		nxt[lst[i]]=i;
	}
	if(!f){
		for(int i=1; i<=m; i++){
			printf("%d ",d[i]);
//			if(i<m) printf(" ");
		}
		return 0;
	}
	memset(d,0,sizeof(d));
	if(m<=2){
		for(int i=1; i<=n; i++){
			if(a[i]!=a[n]){
				d[a[i]]++;
			}
			d[a[n]]++;
		}
		for(int i=1; i<=m; i++){
			printf("%d ",d[i]);
		}
		return 0;
	}
	if(n<=500&&m<=200){
		for(int i=1; i<=n; i++){
//		memset(cnt,0,sizeof(cnt));
//		memset(lst,0,sizeof(lst));
//		memset(d,0,sizeof(d));
			for(int j=i; j<=n; j++){
				b[j]=a[j];
			}
			for(int j=i;j<=n;j++){
				if(cnt[b[j]]){
					for(int k=lst[b[j]]; k<j; k++){
						cnt[b[k]]--;
						if(b[lst[b[k]]]==0){
							lst[b[k]]=lst[lst[b[k]]];
						}
	//					cout<<"DEL:"<<k<<endl;
						b[k]=0;
					}
				}
				cnt[b[j]]++;
				lst[b[j]]=j;
			}
			for(int j=i; j<=n; j++){
	//			cout<<b[j]<<" ";
				if(b[j]!=0){
					d[b[j]]++;
				}
				cnt[b[j]]=0;
				lst[b[j]]=0; 
			}
	//		cout<<endl;
		}
		for(int i=1; i<=m; i++) printf("%d ",d[i]);
	}else{
		memset(d,0,sizeof(d));
		for(int i=1; i<=m; i++){
			int now=fir[i];
			while(nxt[now]!=0){
				now=nxt[now];
			}
//			d[a[now]]+=c[a[now]];
			int r=now;
			while(r<=n){
	//			printf("%d %d\n",i,r);
				d[a[r]]+=c[a[now]];
	//			cout<<a[r]<<" "<<c[a[now]]<<endl;
				while(nxt[r]!=0){
	//				printf("%d\n",r);
					r=nxt[r];
				}
	//			printf("%d\n",r);
				r++;
			}
		}
		for(int i=1; i<=m; i++) printf("%d ",d[i]);
	}
	return 0;
}
/*
100+100+100+48???

为了理清思路，把想到的都写到了这里。 
lz1333t 的 T4 思路： 
BIT 可能可以优化 34-41 行，从 O(n)->O(log n)。
但是测试点 7~9 n<=5000,m<=3000，log 不可行，要 O(n^2)，就是直接省掉一层循环。

特殊性质 A：
eg. 1 1 2 3 3
因为数组单调不降，所以每一种数的最后一个数不可能被删掉。除非游戏开始时该数不被操作。
答案应为每一种数最后一次出现的下标。 

特殊性质 B：
观察到数组最后一个数在每一轮游戏中都不会被删掉，那么 d[a[n]]=n
每一轮游戏中的第一个数也会保留到结束，因为它如果被删那就只能是被后面的同类消掉，然后同类变成第 1 个，所以也会保留。

枚举每一轮游戏，如果 a[i]=a[n] 那 d[a[n]]++，否则两个都 ++
这也许对我们的正解有很大启发，是一个考虑方向。应该能推广到 m 更大的时候。 

测试点 7~12 的另一种思路：
正难则反。第一层循环能否考虑从 n->1？

还有一种可能：
在草稿纸上运行样例 2，发现会末尾有一些相同的周期。
 

更多想法：
n<=5*10^5,m<=3*10^5。
那就需要 log 的时间复杂度。
这怎么和 luogu 上的 GESP 8 级那个接竹竿那么像？ 
正解应该是倍增。 
考虑倍增。

当前时间复杂度：O(nm)？
*/
