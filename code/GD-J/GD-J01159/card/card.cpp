#include<bits/stdc++.h>
using namespace std;
long long n,m,l[300010],v[300010],f[300010];
long long a[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[a[i]]+=i;
	}
	for(int i=1;i<=m;i++){
		for(int j=i;j<=n;j++){
			v[a[j]]++;
			if(v[a[j]]==2){
				l[a[j]]++;
			}
		} 
    }sort(a+1,a+n+1);
	for(int i=1;i<=a[n];i++){
		cout<<f[i]-l[i]<<" ";
	}
    return 0;
}//呃呃呃呃呃呃呃呃呃呃
//我是真的写不下去了 
//不知道，到时候有没有人会看到我代码
//一想到这我就想笑
//前面的：非常认真，过程仔细，没有bug
//我：梦到哪里写哪里，最后还附赠垃圾玩意 
//哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈 