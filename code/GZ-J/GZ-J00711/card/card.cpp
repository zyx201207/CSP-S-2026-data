//凯里市第一初级中学 刘泓毅 GZ-J00711
#include<bits/stdc++.h>
#define max 5e+5
typedef long long int lld;
using namespace std;
bool q=0;
int search(vector<int>lis,lld target){
	for(int i=0;i<lis.size();i++){
		if(target==lis[i]){q=1;return i;}
	}
	q=0;
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	lld m,n;
	scanf("%lld %lld",&n,&m);
	vector<lld>card(n,0),ans(m+1,0);
	for(lld i=0;i<n;i++)scanf("%lld",&card[i]);
	for(int i=0;i<n;i++){
		vector<int>lis;
		for(int o=i;o<n;o++){
			int fid=search(lis,card[o]);
			if(fid||q)for(int i=o;i<=lis.size();i++)lis.pop_back();
			else lis.push_back(card[o]);
		}
		for(int o=1;o<=m;o++)if(search(lis,o)||q)ans[o]+=1;
	}
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	return 0;
}

