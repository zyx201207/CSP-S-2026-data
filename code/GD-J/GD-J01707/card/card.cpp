#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5000001],mk[3000001],table[3000001],ans[3000001];
int main(){
	//我常常追忆过去。。。
	//10. 考生不能在注释中写侮辱性话语、歌词、诗词、散文等与考试无关的话语，若有违反可能会收到取消成绩或以上处分。
	//[BANed]
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int _=1;_<=n;_++){
		memset(mk,0,sizeof(mk));
		memset(table,0,sizeof(table));
		int now=0;
		for(int i=_;i<=n;i++){
			if(mk[a[i]]!=0){
				int k=now+1;
				now=mk[a[i]];
				for(int j=mk[a[i]];j<=k;j++){
					mk[table[j]]=0;
					table[j]=0;
				}
				table[now]=a[i];
				mk[a[i]]=now;
				continue;
			}
			table[++now]=a[i];
			mk[a[i]]=now;
		}
		for(int i=1;i<=now;i++){
			ans[table[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	//我只是打出了西西弗三个字母就引起了评测机的注意
	//明明就很在意我嘛 
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
