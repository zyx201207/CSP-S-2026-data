#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
unordered_set<int> st[35];
unordered_set<int> choose,tmp;
unordered_set<int>::iterator it;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		choose.insert(i);
		for(int j=0;j<=30;j++){
			if((a[i]>>j)&1)  st[j].insert(i);
		}
	}
//	for(int j=0;j<=30;j++){
	//	cout<<j<<": ";
//		for(it=st[j].begin();it!=st[j].end();it++){
//			cout<<*it<<" ";
//		}
//		cout<<endl;
//	}
	int ans=0;
	for(int i=30;i>=0;i--){
		tmp=st[i];
		for(it=tmp.begin();it!=tmp.end();it++){
			if(!choose.count(*it))  st[i].erase(*it);
		}
		if((int)st[i].size()>=m){
			choose=st[i];
			ans|=(1<<i);
		}
	}
	printf("%d",ans);
	return 0;
}
