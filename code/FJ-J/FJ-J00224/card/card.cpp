#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],b[N],vis[N],n,m,mm; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(m>200&&n>500){
		int last=a[1];
		vis[a[1]]=1;
		for(int i=2;i<=n;i++){
			if(a[i]==last) vis[i]++;
			else{
				vis[i]=i;
				last=a[i];
			}
		}
		for(int i=1;i<=m;i++) cout<<vis[i]<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=1;k<=n;k++){
		memset(b,0,sizeof b);
		mm=0;
		for(int i=k;i<=n;i++){
			int x=a[i],f=1,fl=mm+1;
			for(int j=1;j<=mm;j++){
				if(b[j]==x){
					f=0;
					fl=j;
					break;
				}
			}
			if(f) b[++mm]=x;
			else{
				b[fl]=x;
				mm=fl;
			}
		}
		for(int i=1;i<=mm;i++) vis[b[i]]++;
	}
	for(int i=1;i<=m;i++) cout<<vis[i]<<' ';
	return 0;
}
/*
连千级都过不去T-T 
+特殊A
还有十五分钟，写个游记~ 
8：05进校
8：30开考
8：45读完题并准备好文件夹；
9：05拿下第一题
9：10跳过第二题
9：10跳过第三题
9:35？打完第四题模拟 
10：50打完第三题前20分
10：10优化完第四题
10：25优化完第三题 
10：30小恐龙（3725分）
11：00阿巴阿巴（在看第二题）
11：20正在深度求索
11：30打完暴力
11：35开智
11：45打完第二题
吐槽一下密码：Trick||Treat!  
还有五分钟结束 
不热不冷的知识：10.31是蒋介石的生日。
 
                    		--快乐的元首 
*/
