/*

I know I'm still shining

我将使用双指针来解决这道题
把题目全部看了一遍，为什么没有搜索（
难道说搜索已经过时了吗
还是说太难了
明显今年T2比24年简单好吧
*/
#include <bits/stdc++.h>
using namespace std;

const int N=2e5+10;
int n,a[N];
char ch[N];
long long ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>ch[i];
	int l=1,r=n;
	while(l<r){
		if(ch[l]==ch[r]){
			if(a[l]<a[r]) a[r]-=a[l++];
			else if(a[r]<a[l]) a[l]-=a[r--];
			else l++,r--;
		}
		else{
			if(a[l]<a[r]) ans+=a[l],a[r]-=a[l++];
			else if(a[r]<a[l]) ans+=a[r],a[l]-=a[r--];
			else ans+=a[l],l++,r--;
		}
	}
	cout<<ans;
	return 0;
}
