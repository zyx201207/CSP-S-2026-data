#include <bits/stdc++.h>
using namespace std;
int n,m;
bool bits[35][200005],ans[35]; // 从低到高
bool ban[200005]; // 是否不选
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a,cnt=0;
		cin>>a;
		while(a) bits[++cnt][i]=a&1,a/=2;
	}
	for(int i=30;i>=1;i--){
		int cnt=0;
		for(int j=1;j<=n;j++)
			if(!ban[j])
				cnt+=bits[i][j];
		if(cnt<m) continue;
		ans[i]=1;
		for(int j=1;j<=n;j++)
			if(!bits[i][j])
				ban[j]=1;
	}
	int cnt=0;
	for(int i=1;i<=30;i++)
		if(ans[i])
			cnt+=1<<(i-1);
	cout<<cnt;
	return 0;
}
// [10:10] 哦不对不对，T3 怎么这么简单
